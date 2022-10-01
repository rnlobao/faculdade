A proposta é modelar um banco de dados na qual o tema do minimundo é uma corretora de investimentos em que um usuário pode fazer investimentos, consultar analistas e escolher classes de ativos, segue as infos:

<details>
  <summary>Minimundo</summary>
  Uma corretora de valores brasileira, que intermedia a compra e a venda de ativos financeiros a seus usuários, deseja manter todos os dados em relação a eles e sobre suas transações. Fizemos um diagrama Entidade Relacionamento Estendido para isso, seguindo as seguintes especificações:  
Deve-se guardar para cada usuário um código (único), nome, seu(s) telefone(s) e endereço completo (incluindo logradouro, número, complemento, bairro, CEP, cidade e Estado). Além disso, ele possui credenciais (login e senha) para ter acesso aos seus investimentos e dados pessoais (caso deseje alterar). 
O usuário pode ser classificado como:
Pessoa física, que possui sexo, data de nascimento e estado civil;
Pessoa jurídica, que possui CNAE (Classificação Nacional de Atividades Econômica), situação cadastral (CNPJ) e data de abertura do CNPJ;
Fundo de investimento, que é a comunhão de recursos, captados de pessoas físicas ou jurídicas, o qual possui um tipo.

O usuário realiza investimentos em uma classe de ativos utilizando um certo valor da transação, que é o valor corrente daquele ativo naquele dia, a quantidade que ele vai comprar, o valor total da movimentação financeira, que pode ser deduzido pelas outras informações dadas, e data de compra. Cada classe de ativos conta com um código (único) e sua rentabilidade média mensal. 
Existem 3 tipos de classes de ativos, sendo elas:
renda fixa, que possui um grupo e, além disso, ela possui um rendimento médio, que é o valor que ela vendeu nos últimos meses. Esse rendimento médio possui uma porcentagem e data de rendimento.  
fundo de investimento imobiliário, que possui um setor, Dividend Yield (rendimento do dividendo) e gestora;  
ações, que possuem também um tipo, seu caixa, preço sobre lucro e a dívida. Algo importante sobre as ações é que elas podem ser BDRs. O BDR possui a fração que o representa e a empresa estrangeira que é correspondida. Ele é lastreado em uma moeda estrangeira, que possui uma abreviação (única), um lastro e país(es) onde ela é comercializada.

O usuário pode realizar investimentos com ou sem ajuda de um analista, que tem mais conhecimentos sobre as classes de ativos. Essa consulta com o analista pode ou não resultar em um investimento por parte desse usuário. O analista possui um NSS (único), nome, credenciais (login e senha), telefone(s) e endereço completo (incluindo logradouro, número, complemento, bairro, CEP, cidade e Estado). Um analista também pode ser de diversos tipos: analista fundamentalista, analista técnico e analista sênior.
As classes de ativos são detidas pelas bolsas de valores, que, por sua vez, possuem uma abreviação (única), um nome e um índice que é atualizado diariamente. 
</details>

<details>
  <summary>Modelo conceitual ERE</summary>
       <img alt="image" src="https://user-images.githubusercontent.com/66230142/188343654-5ed65bfd-c719-4de5-b914-e6a2be80fa36.jpeg"> 
 </details>
 
 <details>
  <summary>Mapeamento relacional</summary>
    
 </details>
 
  <details>
  <summary>Esquema físico</summary>
    
 </details>



