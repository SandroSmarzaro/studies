SELECT * FROM tabela													//Importa todos campos da tabela
SELECT nome, cpf FROM tabela												//Importa campos específicos da tabela
SELECT * FROM tabela WHERE id = 1											//Importa campos com id=1
SELECT * FROM tabela	 												//Importa campos com nome que começa como fulano
WHERE nome like "fulano%"

<> Não igual
WHERE id NOT BETWEEN 1 and 10												//Importa campos com id não esteja de 1 a 10 
WHERE id NOT IN (1, 5, 10)												//Importa campos com id diferente de 1, 5 e 10
WHERE id IS NOT NULL													//Importa campos com id diferente de NULL

INSERT INTO tabela(nome, cpf) VALUES ("fulano", 123)									//Inserir dados novos na tabela
UPDATE tabela SET nome="fulano", celular=123 WHERE id = 1								//Alterar dados na tabela
DELETE FROM tabela WHERE id = 1												//Deletar dados na tabela
	
SELECT * FROM tabela1 JOIN tabela2 ON tabela2.id2 = tabela1.id1								//Unir duas tabelas com uma condição de amostra
SELECT * FROM tabela1 JOIN tabela2 ON tabela2.id2 = tabela1.id1 WHERE tabela1.id1 = 1					//Unir duas tabelas com condição de amostra e WHERE
SELECT tabela1.nome, tabela1.cpf FROM tabela1 JOIN tabela2 ON tabela2.id2 = tabela1.id1 WHERE tabela1.id1 = 1		//Unir duas tabelas com campos especificos
SELECT t1.nome as NOME, t1.cpf as CPF FROM tabela1 as t1 JOIN tabela2 as t2 ON t2.id2 = t1.id1 WHERE t1.id1 = 1		//Criando alias dos campos
SELECT * FROM tabela1 LEFT OUTER JOIN tabela2 ON tabela2.id2 = tabela1.id1						//Priorizando exebição de tabelas a esquerda

SELECT * FROM tabela ORDER BY nome DESC											//Ordenando de forma descrescente
SELECT * FROM tabela LIMIT 1 OFFSET 1											//Limitando quantos dados mostrados ignorando outros tantos
SELECT COUNT(id) FROM tabela 												//Contando o número de dados dauqle campo(não conta NULL)
SELECT id, COUNT(id) FROM  tabela GROUP BY id										//Conta o número de agrupamentos(campos diferentes)
SELECT tabela2.nome, COUNT(tabela1.id1) FROM tabela1 JOIN tabela2 ON tabela1.id1 = tabela2.id2 GROUP BY tabela2.id2	//Contando o número de nomes e mostrando a contagem com o nome ao lado
SELECT tabela2.nome, COUNT(tabela1.id1) FROM tabela1 JOIN tabela2 ON tabela1.id1 = tabela2.id2 GROUP BY tabela2.id2 HAVING COUNT(tabela1.id1) >= 2	//Mesma coisa só que mostrando auqles com pelo menos 2

CREATE TABLE tabela1 (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	nome TEXT,
	cpf INTEGER UNIQUE,
	number INTEGER,
	FOREIGN (number) REFERENCES tabela2(number)
)
ALTER TABLE tabela1 RENAME TO primeiraTabela
ALTER TABLE tabela1 RENAME COLUMN number TO phone
DROPE TABLE tabela1 