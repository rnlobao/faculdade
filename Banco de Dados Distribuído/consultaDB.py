def bombardear():
    for i in range(3):
        secondName = f"Silva{i}"
        cur.execute('INSERT INTO funcionario (first_name, last_name, email, gender, ip_address) VALUES (%s, %s, %s, %s, %s)', ("Lucas",
        secondName, "email@gmail.com", "Male", "1.0.2.77"))
        print(f"Usuário Lucas {secondName} inserido no banco\n")

db_hostCoordinator = "34.74.48.58"
db_nameCoordinator = "postgres"
db_userCoordinator = "postgres"
db_passCoordinator = "188x"

#db_hostWorker = "34.73.3.156"
#db_nameWorker = "postgres"
#db_userWorker = "postgres"
#db_passWorker = "188x"

db_name = "funcionario"

import psycopg2
import threading

conn = psycopg2.connect(dbname=db_nameCoordinator, user=db_userCoordinator, password=db_passCoordinator, host=db_hostCoordinator)
#conn = psycopg2.connect(dbname=db_nameWorker, user=db_userWorker, password=db_passWorker, host=db_hostWorker)

cur = conn.cursor()

n = int(input("Conexão concluída, o que gostaria de fazer?\n1) Inserir dado no banco de funcionários\n2)Consultar um funcionário\n3)Ver worker nodes\n4) Estressar Aplicação com inserts\n5) Estressar aplicacao com Threads\n"))

if n == 1:
    firstname = input("Qual o primeiro nome? ")
    secondname = input("Qual o segundo nome? ")
    email = input("Qual o email? ")
    gender = input("Qual o gênero? ")
    ipAddres = input("Qual o endereço de ip? ")

    cur.execute('INSERT INTO funcionario (first_name, last_name, email, gender, ip_address) VALUES (%s, %s, %s, %s, %s)', (firstname,
     secondname, email, gender, ipAddres))
    print(f"Usuário %s inserido no banco!\n", firstname)

if n == 2:
    busca = input("Digite o nome do usuário: ")
    comandoDeBusca = f"SELECT * FROM funcionario WHERE first_name='{busca}'"
    cur.execute(comandoDeBusca)
    records = cur.fetchall()
    print("\n\nNumero de resultados: ", len(records))
    for row in records:
        print("Id: ", row[0])
        print("First_Name: ", row[1])
        print("Last Name: ", row[2])
        print("Email: ", row[3])
        print("Gender: ", row[4])
        print("Ip Address: ", row[5])
        print("\n")

if n == 3:
    cur.execute("SELECT * FROM citus_get_active_worker_nodes();")
    print(cur.fetchall())

if n == 4:
    quantidadeDeVezes = int(input("Quantos inserts você gostaria de fazer? "))
    for i in range(quantidadeDeVezes):
        secondName = f"Silva{i}"
        cur.execute('INSERT INTO funcionario (first_name, last_name, email, gender, ip_address) VALUES (%s, %s, %s, %s, %s)', ("Matheus",
        secondName, "email@gmail.com", "Male", "1.0.2.3"))
        print(f"Usuário Matheus {secondName} inserido no banco\n")

if n == 5:
    nThreads = int(input("Quantas threads? "))
    threads = []
    for i in range(nThreads):
        t = threading.Thread(target= bombardear)
        t.start()
        threads.append(t)
    for thread in threads:
        thread.join()

conn.commit()
cur.close()
conn.close()