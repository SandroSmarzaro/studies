CREATE TABLE departamento (
	cod_departamento SERIAL,
	nome_departamento VARCHAR(40) NULL
		DEFAULT 'Novo Departamento',
	CONSTRAINT pk_cod_departamento
		PRIMARY KEY (cod_departamento)
);

ALTER TABLE departamento
	ALTER COLUMN nome_departamento DROP DEFAULT,
	ALTER COLUMN nome_departamento SET DEFAULT 'Departamento Novo';
	
DROP TABLE departamento;

CREATE DOMAIN do_salario
	NUMERIC(9,2) NOT NULL
	DEFAULT 1100
	CONSTRAINT ck_do_salario
		CHECK (VALUE > 0);

CREATE TABLE empregado (
	matricula INTEGER NOT NULL,
	num_departamento INTEGER NOT NULL,
	nome_empregado VARCHAR(40) NULL,
	salario do_salario,
	cpf CHAR(14) NOT NULL,
	CONSTRAINT pk_empregado 
		PRIMARY KEY (matricula),
	CONSTRAINT fk_empregado_departamento
		FOREIGN KEY (num_departamento)
		REFERENCES departamento(cod_departamento)
		ON DELETE CASCADE,
	CONSTRAINT un_empregado_cpf
		UNIQUE (cpf)
);

DROP TABLE IF EXISTS empregado;

ALTER TABLE empregado
	ADD COLUMN telefone CHAR(14) NULL,
	ADD CONSTRAINT ck_empregado_matricula
		CHECK (matricula > 0);
		
ALTER TABLE empregado
	VALIDATE CONSTRAINT ck_empregado_matricula;
	
ALTER TABLE empregado
	ALTER COLUMN nome_empregado TYPE VARCHAR(30);
	
ALTER TABLE empregado 
	RENAME COLUMN num_departamento TO num_dep;
	
ALTER TABLE empregado
	ALTER COLUMN nome_empregado SET NOT NULL,
	ALTER COLUMN nome_empregado DROP NOT NULL;
	
ALTER TABLE empregado
	DROP COLUMN nome_empregado,
	DROP CONSTRAINT fk_empregado_departamento;

CREATE SEQUENCE seq_projeto;

CREATE TABLE projeto (
	cod_projeto INTEGER NOT NULL DEFAULT
		NEXTVAL('seq_projeto'),
	CONSTRAINT pk_cod_projeto
		PRIMARY KEY (cod_projeto)
);

ALTER SEQUENCE seq_projeto
	OWNED BY projeto.cod_projeo;
	
DROP SEQUENCE IF EXISTS seq_projeto;

DROP TABLE IF EXISTS projeto;