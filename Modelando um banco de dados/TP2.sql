SET datestyle = GERMAN, DMY;

CREATE TABLE Usuario (
    codigo serial PRIMARY KEY,
    nome VARCHAR ( 50 ) NOT NULL,
    login VARCHAR ( 20 ) UNIQUE NOT NULL,
    senha VARCHAR ( 50 ) NOT NULL,
    logradouro VARCHAR ( 50 ) NOT NULL,
    complemento VARCHAR ( 20 ),
    numero INT NOT NULL,
    bairro VARCHAR ( 50 ) NOT NULL,
    CEP DECIMAL (8,0) NOT NULL, -- Certo?
    cidade VARCHAR ( 50 ) NOT NULL,
    estado CHAR (2) NOT NULL
);
 
CREATE TABLE Telefone_usuario (
    codigo_usuario INT NOT NULL,
    telefone VARCHAR ( 20 ) NOT NULL, -- Certo?
    CONSTRAINT FK_Usuario FOREIGN KEY (codigo_usuario) REFERENCES Usuario (codigo)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);
 
CREATE TABLE Pessoa_Fisica (
    codigo_usuario INT UNIQUE NOT NULL,
       sexo CHAR ( 1 ) NOT NULL,
    data_nascimento TIMESTAMP NOT NULL,
    CONSTRAINT FK_Usuario FOREIGN KEY (codigo_usuario) REFERENCES Usuario (codigo)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

CREATE TABLE Pessoa_Juridica (
    codigo_usuario INT UNIQUE NOT NULL,
    CNAE INT NOT NULL,
    data_abertura TIMESTAMP NOT NULL,
    situacao_cadastral VARCHAR ( 20 ) NOT NULL,
    CONSTRAINT FK_Usuario FOREIGN KEY (codigo_usuario) REFERENCES Usuario (codigo)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

CREATE TABLE Bolsa_valores (
    nome VARCHAR ( 75 ) UNIQUE NOT NULL,
    abreviacao VARCHAR ( 10 ) PRIMARY KEY,
    indice DECIMAL (9, 2) NOT NULL -- Certo?
);
 
CREATE TABLE Classe_ativos (
    bolsa VARCHAR ( 10 ) NOT NULL,
    codigo VARCHAR ( 25 ) PRIMARY KEY,
    CONSTRAINT FK_Ativos FOREIGN KEY (bolsa) REFERENCES Bolsa_valores (abreviacao)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT
);
 
CREATE TABLE Fundo_Investimentos (
    codigo_usuario INT UNIQUE NOT NULL,
    tipo VARCHAR ( 25 ) NOT NULL,
    CONSTRAINT FK_Usuario FOREIGN KEY (codigo_usuario) REFERENCES usuario (codigo)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);
 
CREATE TABLE Analista (
    nss INT UNIQUE NOT NULL PRIMARY KEY,
    nome VARCHAR ( 50 ),
    tipo VARCHAR ( 20 ) NOT NULL,
    login VARCHAR ( 20 ) UNIQUE NOT NULL,
    senha VARCHAR ( 50 ) NOT NULL,
    logradouro VARCHAR ( 50 ) NOT NULL,
    complemento VARCHAR ( 20 ),
    numero INT NOT NULL,
    bairro VARCHAR ( 50 ) NOT NULL,
    CEP DECIMAL (8,0) NOT NULL, -- Certo?
    cidade VARCHAR ( 50 ) NOT NULL,
    estado CHAR (2) NOT NULL
);
 
CREATE TABLE Telefone_analista (
    nss_analista INT NOT NULL,
    telefone VARCHAR ( 20 ) NOT NULL, -- Certo?
    CONSTRAINT FK_Analista FOREIGN KEY (nss_analista) REFERENCES Analista (nss)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);
 
 
CREATE TABLE Renda_Fixa(
    codigo VARCHAR ( 25 ) PRIMARY KEY,
    grupo VARCHAR ( 10 ) NOT NULL,
    porcentagem NUMERIC (3, 2) NOT NULL,
    dia_rendimento INT NOT NULL CHECK (dia_rendimento BETWEEN 1 AND 31),
    CONSTRAINT FK_Renda_Fixa FOREIGN KEY (Codigo) REFERENCES Classe_ativos (codigo)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

CREATE TABLE FII(
    codigo VARCHAR ( 25 ) PRIMARY KEY,
    setor VARCHAR ( 30 ) NOT NULL,
    dy NUMERIC (3, 2) NOT NULL,
    gestora VARCHAR ( 50 ) NOT NULL,
    CONSTRAINT FK_FII FOREIGN KEY (Codigo) REFERENCES Classe_ativos (codigo)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);

CREATE TABLE Acao(
    codigo VARCHAR ( 25 ) PRIMARY KEY,
    caixa DECIMAL (100,0) NOT NULL,
    tipo VARCHAR ( 10 ) NOT NULL,
    divida DECIMAL (12,1) NOT NULL,
    CONSTRAINT FK_ACAO FOREIGN KEY (Codigo) REFERENCES Classe_ativos (codigo)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);
 
CREATE TABLE Moeda(
    abreviacao VARCHAR ( 5 ) PRIMARY KEY,
    lastro VARCHAR ( 50 ) NOT NULL
);
 
CREATE TABLE Moedas_Pais(
    moeda VARCHAR ( 5 ) PRIMARY KEY,
    pais VARCHAR ( 50 ) NOT NULL,
    CONSTRAINT FK_MOEDA_PAIS FOREIGN KEY (Moeda) REFERENCES Moeda(abreviacao)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);
 
CREATE TABLE BDR(
    codigo VARCHAR ( 25 ) PRIMARY KEY,
    empresa_estrangeira VARCHAR ( 50 ) NOT NULL,
    fracao DECIMAL (2,0) NOT NULL,
    moeda VARCHAR ( 5 ) NOT NULL,
    CONSTRAINT FK_BDR_ACAO FOREIGN KEY (codigo) REFERENCES Acao(codigo)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
    CONSTRAINT FK_BDR_MOEDA FOREIGN KEY (moeda) REFERENCES Moeda(abreviacao)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT
);
 
CREATE TABLE Consulta(
    id_consulta serial NOT NULL PRIMARY KEY,
    codigo_usuario INT NOT NULL,
    nss_analista INT NOT NULL,
    CONSTRAINT FK_CONSULTA_USUARIO FOREIGN KEY (codigo_usuario) REFERENCES Usuario(codigo)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT,
    CONSTRAINT FK_CONSULTA_ANALISTA FOREIGN KEY (nss_analista) REFERENCES Analista(nss)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT
);
 
CREATE TABLE Investimento(
    codigo_usuario INT NOT NULL,
    data_compra TIMESTAMP NOT NULL,
    valor_corrente DECIMAL (8, 2) NOT NULL,
    quantidade INT NOT NULL,
    codigo_ativo VARCHAR ( 25 ) NOT NULL,
    PRIMARY KEY (codigo_usuario, data_compra),
    CONSTRAINT FK_INVESTIMENTO_USUARIO FOREIGN KEY (codigo_usuario) REFERENCES Usuario(codigo)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
    CONSTRAINT FK_INVESTIMENTO_CLASSE_ATIVOS FOREIGN KEY (codigo_ativo) REFERENCES Classe_Ativos(codigo)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT
);

CREATE TABLE Resulta_em(
    id_consulta INT NOT NULL,
    codigo_usuario INT NOT NULL,
    data_compra TIMESTAMP NOT NULL,
    CONSTRAINT FK_RESULTA_EM_INVESTIMENTO FOREIGN KEY (codigo_usuario, data_compra) REFERENCES Investimento (codigo_usuario, data_compra)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT,
    CONSTRAINT FK_RESULTA_EM_CONSULTA FOREIGN KEY (id_consulta) REFERENCES Consulta (id_consulta)
    ON DELETE RESTRICT
    ON UPDATE RESTRICT
);

INSERT INTO usuario (nome, login, senha, logradouro, complemento, numero, bairro, cep, cidade, estado) VALUES ('Pedro Lucas', 'pedrold', '123teste', 'Artur Vitorino Coelho', 'APTO. 201', 181, 'Bauxita', 35400000, 'Ouro Preto', 'MG');
INSERT INTO usuario (nome, login, senha, logradouro, complemento, numero, bairro, cep, cidade, estado) VALUES ('Fernanda Teixeira', 'fteixeira', 'senha456', 'Padre Pedro Evangelista', 'Casa', 33, 'São Bento', 49500000, 'Curitiba', 'PR');
INSERT INTO usuario (nome, login, senha, logradouro, complemento, numero, bairro, cep, cidade, estado) VALUES ('Paulo Gabeira', 'paulog', 'paulo113', '21 de Abril', NULL, 919, 'São Dimas', 39655000, 'São Paulo', 'SP');
INSERT INTO usuario (nome, login, senha, logradouro, complemento, numero, bairro, cep, cidade, estado) VALUES ('XD Investimentos', 'xdinvest', 'xd1nv35st', 'Doutor Campolina', 'APTO. 505', 65, 'Novo Horizonte', 59660040, 'Ipatinga', 'MG');
INSERT INTO usuario (nome, login, senha, logradouro, complemento, numero, bairro, cep, cidade, estado) VALUES ('HaHa Solucoes Digitais', 'rsrssd', 'risosd123', 'Abelard Dutra', NULL, 5515, 'Funcionários', 95544000, 'Florianópolis', 'SC');

INSERT INTO pessoa_fisica (codigo_usuario, sexo, data_nascimento) VALUES (1, 'M', '01/03/1998');
INSERT INTO pessoa_fisica (codigo_usuario, sexo, data_nascimento) VALUES (2, 'F', '12/09/1995');
INSERT INTO pessoa_fisica (codigo_usuario, sexo, data_nascimento) VALUES (3, 'M', '05/11/2002');
INSERT INTO fundo_investimentos (codigo_usuario, tipo) VALUES (4, 'Fundo Multimercado');
INSERT INTO pessoa_juridica (codigo_usuario, cnae, data_abertura, situacao_cadastral) VALUES (5, 6201501, '01/10/2005', 'Ativo');

INSERT INTO telefone_usuario (codigo_usuario, telefone) VALUES (1, '(31) 9 6885-9119');
INSERT INTO telefone_usuario (codigo_usuario, telefone) VALUES (2, '(37) 9 9959-9516');
INSERT INTO telefone_usuario (codigo_usuario, telefone) VALUES (3, '(41) 3555-1301');
INSERT INTO telefone_usuario (codigo_usuario, telefone) VALUES (4, '(11) 6965-1101');
INSERT INTO telefone_usuario (codigo_usuario, telefone) VALUES (5, '(55) 5969-6959');

INSERT INTO analista (nss, nome, tipo, login, senha, logradouro, complemento, numero, bairro, CEP, cidade, estado) VALUES (1, 'Fernando Paes', 'F.I.', 'fernandop', 'fer123', 'Adalgisa Soares Cardoso', 'APTO. 110', 50, 'Cristóvão Colombo', 69922000, 'Extrema', 'MG');
INSERT INTO analista (nss, nome, tipo, login, senha, logradouro, complemento, numero, bairro, CEP, cidade, estado) VALUES (2, 'Karina Peixoto', 'BDR', 'karinapeixoto', 'kar1n4p', 'Adamastor Augusto', 'Casa', 100, 'Manoel Corrêa', 44072000, 'Ouro Preto', 'MG');
INSERT INTO analista (nss, nome, tipo, login, senha, logradouro, complemento, numero, bairro, CEP, cidade, estado) VALUES (3, 'Amanda Teixeira', 'Multimercado', 'amdteixeira', '4m4nd4', 'Adelina Amaral', 'Casa', 202, 'Santo Agostinho', 49942111, 'Belo Horizonte', 'MG');

INSERT INTO telefone_analista (nss_analista, telefone) VALUES (1, '(38) 9 6866-9059');
INSERT INTO telefone_analista (nss_analista, telefone) VALUES (2, '(32) 9 9559-9516');
INSERT INTO telefone_analista (nss_analista, telefone) VALUES (3, '(45) 9 1929-1301');

INSERT INTO bolsa_valores (nome, abreviacao, indice) VALUES ('Brasil, Bolsa, Balcão', 'B3', 112072);
INSERT INTO bolsa_valores (nome, abreviacao, indice) VALUES ('National Association of Securities Dealers Automated Quotations', 'NASDAQ', 10692);
INSERT INTO bolsa_valores (nome, abreviacao, indice) VALUES ('Standard & Poors 500', 'S&P', 3583);
INSERT INTO bolsa_valores (nome, abreviacao, indice) VALUES ('Dow Jones Industrial Average', 'Dow Jones', 29634);

INSERT INTO moeda (abreviacao, lastro) VALUES ('USD', 'Ouro');
INSERT INTO moedas_pais (moeda, pais) VALUES ('USD', 'Estados Unidos da América');

INSERT INTO classe_ativos (bolsa, codigo) VALUES ('B3', 'ENGI11');
INSERT INTO acao (codigo, caixa, tipo, divida) VALUES ('ENGI11', 58260000000, 'UNIT', 27220000000);
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('B3', 'ENGI13');  
INSERT INTO acao (codigo, caixa, tipo, divida) VALUES ('ENGI13', 58260000000, 'ON', 27220000000);
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('B3', 'ENGI14');
INSERT INTO acao (codigo, caixa, tipo, divida) VALUES ('ENGI14', 58260000000, 'PN', 27220000000);
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('B3', 'MGLU3');
INSERT INTO acao (codigo, caixa, tipo, divida) VALUES ('MGLU3', 34500000000, 'ON', 6840000000);
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('B3', 'ITUB4');
INSERT INTO acao (codigo, caixa, tipo, divida) VALUES ('ITUB4', 2165600000000, 'PN', -33830000000);
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('NASDAQ', 'AAPL34');
INSERT INTO acao (codigo, caixa, tipo, divida) VALUES ('AAPL34', 10000000000000, 'DRN', 40000000000);
INSERT INTO bdr (codigo, empresa_estrangeira, fracao, moeda) VALUES ('AAPL34', 'Apple Inc.', 1, 'USD');
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('Dow Jones', 'GSGI34');
INSERT INTO acao (codigo, caixa, tipo, divida) VALUES ('GSGI34', 104510000000, 'DRN', -6554000000);
INSERT INTO bdr (codigo, empresa_estrangeira, fracao, moeda) VALUES ('GSGI34', 'Goldman Sachs', 1, 'USD');
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('B3', 'ABCP11');
INSERT INTO fii (codigo, setor, dy, gestora) VALUES ('ABCP11', 'Shoppings', 0.72, 'Rio Bravo Investimentos LTDA');
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('B3', 'AFHI11');
INSERT INTO fii (codigo, setor, dy, gestora) VALUES ('AFHI11', 'Títulos e Val. Mob.', 1.19, 'Af Invest');
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('B3', 'ALZR11');
INSERT INTO fii (codigo, setor, dy, gestora) VALUES ('ALZR11', 'Logística', 4.82, 'Alianza Trust Renda Imobiliária');
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('B3', 'Tesouro Direto');
INSERT INTO renda_fixa (codigo, grupo, porcentagem, dia_rendimento) VALUES ('Tesouro Direto', 'B3', 0.014, 15);
INSERT INTO classe_ativos (bolsa, codigo) VALUES ('B3', 'CDB');
INSERT INTO renda_fixa (codigo, grupo, porcentagem, dia_rendimento) VALUES ('CDB', 'B3', 0.03, 1);

INSERT INTO consulta (codigo_usuario, nss_analista) VALUES (1, 1);
INSERT INTO consulta (codigo_usuario, nss_analista) VALUES (2, 2);
INSERT INTO consulta (codigo_usuario, nss_analista) VALUES (3, 3);
INSERT INTO consulta (codigo_usuario, nss_analista) VALUES (4, 2);
INSERT INTO consulta (codigo_usuario, nss_analista) VALUES (5, 1);

INSERT INTO investimento (codigo_usuario, data_compra, valor_corrente, quantidade, codigo_ativo) VALUES (1, '16-10-2022 12:25:20-07', 100.00, 2, 'ENGI11');
INSERT INTO investimento (codigo_usuario, data_compra, valor_corrente, quantidade, codigo_ativo) VALUES (1, '16-10-2022 13:40:10-07', 550.60, 1, 'ENGI13');
INSERT INTO investimento (codigo_usuario, data_compra, valor_corrente, quantidade, codigo_ativo) VALUES (2, '01-07-2022 19:26:14-07', 2000.00, 4, 'MGLU3');
INSERT INTO investimento (codigo_usuario, data_compra, valor_corrente, quantidade, codigo_ativo) VALUES (2, '12-10-2022 11:52:56-07', 600.00, 1, 'ABCP11');
INSERT INTO investimento (codigo_usuario, data_compra, valor_corrente, quantidade, codigo_ativo) VALUES (3, '09-01-2021 21:50:40-07', 20.00, 2, 'ITUB4');
INSERT INTO investimento (codigo_usuario, data_compra, valor_corrente, quantidade, codigo_ativo) VALUES (3, '10-09-2020 00:30:00-07', 3500.00, 1, 'ALZR11');
INSERT INTO investimento (codigo_usuario, data_compra, valor_corrente, quantidade, codigo_ativo) VALUES (4, '12-12-2022 12:36:01-07', 220.00, 5, 'Tesouro Direto');
INSERT INTO investimento (codigo_usuario, data_compra, valor_corrente, quantidade, codigo_ativo) VALUES (4, '27-06-2019 08:00:56-07', 2700.00, 1, 'AAPL34');
INSERT INTO investimento (codigo_usuario, data_compra, valor_corrente, quantidade, codigo_ativo) VALUES (5, '21-02-2022 10:25:25-07', 230.50, 1, 'AFHI11');
INSERT INTO investimento (codigo_usuario, data_compra, valor_corrente, quantidade, codigo_ativo) VALUES (5, '09-10-2021 14:22:10-07', 5900.50, 1,'CDB');

INSERT INTO resulta_em (id_consulta, codigo_usuario, data_compra) VALUES (1, 1, '16-10-2022 13:40:10-07');
INSERT INTO resulta_em (id_consulta, codigo_usuario, data_compra) VALUES (2, 2, '01-07-2022 19:26:14-07');
INSERT INTO resulta_em (id_consulta, codigo_usuario, data_compra) VALUES (3, 3, '09-01-2021 21:50:40-07');
INSERT INTO resulta_em (id_consulta, codigo_usuario, data_compra) VALUES (4, 4, '12-12-2022 12:36:01-07');
INSERT INTO resulta_em (id_consulta, codigo_usuario, data_compra) VALUES (5, 5, '09-10-2021 14:22:10-07');