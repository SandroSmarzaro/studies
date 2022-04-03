/*---------------- EXERCÍCIO 1 ------------------*/
CREATE TABLE tipo_mergulho (
  cod_tipo_mergulho  SERIAL      NOT NULL,
  nome_tipo_mergulho VARCHAR(40) NOT NULL,
  CONSTRAINT pk_tipo_mergulho
    PRIMARY KEY(cod_tipo_mergulho)
);

CREATE TABLE local (
  cod_local  SERIAL      NOT NULL,
  nome_local VARCHAR(30) NOT NULL,
  CONSTRAINT pk_local
  PRIMARY KEY(cod_local)
);

CREATE TABLE telefone_cliente (
  cod_cliente INTEGER    NOT NULL,
  telefone    CHAR(12)   NOT NULL,
  CONSTRAINT pk_telefone_cliente
    PRIMARY KEY(cod_cliente, telefone)  ,
  CONSTRAINT fk_telefone_cliente_cliente
    FOREIGN KEY(cod_cliente)
    REFERENCES Cliente(cod_cliente)
);

CREATE TABLE cliente (
  cod_cliente  SERIAL      NOT NULL,
  nome_cliente VARCHAR(30) NOT NULL,
  genero       CHAR(1)     NOT NULL,
  rua          VARCHAR(40) NOT NULL,
  bairro       VARCHAR(30) NOT NULL,
  cidade       VARCHAR(30) NOT NULL,
  uf           CHAR(2)     NOT NULL,
  CONSTRAINT pk_cliente
    PRIMARY KEY(cod_cliente)
);

CREATE TABLE instrutor (
  cod_instrutor  SERIAL      NOT NULL,
  nome_instrutor VARCHAR(30) NOT NULL,
  CONSTRAINT pk_intrutor
    PRIMARY KEY(cod_instrutor)
);

/*------------------- QUESTÃO 1 ----------------------------*/
CREATE TABLE pacote (
  cod_pacote              INTEGER NOT NULL,
  descricao_pacote        VARCHAR(40) NOT NULL,
  hora_programada_saida   CHAR (5) NOT NULL,
  tempo_pacote            INTEGER NOT NULL,
  cod_tipo_mergulho_p     INTEGER NOT NULL,
  hora_programada_chegada CHAR(5) NOT NULL,
  local_saida             INTEGER NOT NULL,
  local_mergulho          INTEGER NOT NULL,
  local_chegada           INTEGER NOT NULL,
  valor_pacote            NUMERIC(7,2) NOT NULL,
  CONSTRAINT pk_pacote_cod_pacote
    PRIMARY KEY (cod_pacote),
  CONSTRAINT fk_pacote_tipo_mergulho
    FOREIGN KEY (cod_tipo_mergulho_p)
    REFERENCES tipo_mergulho(cod_tipo_mergulho),
  CONSTRAINT fk_pacote_local_local_saida
    FOREIGN KEY (local_saida)
    REFERENCES local(cod_local),
  CONSTRAINT fk_pacote_local_local_mergulho
    FOREIGN KEY (local_mergulho)
    REFERENCES local(cod_local),
  CONSTRAINT fk_pacote_local_local_chegada
    FOREIGN KEY (local_chegada)
    REFERENCES local(cod_local)
);

CREATE TABLE mergulho (
  cod_pacote_m    INTEGER NOT NULL,
  data_mergulho_m DATE    NOT NULL,
  hora_mergulho_m CHAR(5) NOT NULL,
  cod_instrutor_m INTEGER NOT NULL,
  CONSTRAINT pk_mergulho
    PRIMARY KEY (cod_pacote_m, data_mergulho_m, hora_mergulho_m),
  CONSTRAINT fk_mergulho_pacote
    FOREIGN KEY (cod_pacote_m)
    REFERENCES pacote(cod_pacote),
  CONSTRAINT fk_mergulho_instrutor
    FOREIGN KEY (cod_instrutor_m)
    REFERENCES instrutor(cod_instrutor)
);

ALTER TABLE pacote
  ALTER COLUMN cod_pacote SET NOT NULL;



/*------------------- QUESTÃO 2 -------------------------------*/
ALTER TABLE participante
  ADD COLUMN  desconto NUMERIC(7,2) NULL;

UPDATE participante p
  SET desconto = 0;

ALTER TABLE participante
  ALTER COLUMN desconto SET NOT NULL;

/*------------------- QUESTÃO 3 -------------------------------*/
UPDATE participante p
  SET valor_cobrado = pac.valor_pacote
  FROM mergulho m,
       pacote pac
  WHERE p.cod_pacote_p    = m.cod_pacote_m
    AND p.data_mergulho_p = m.data_mergulho_m
    AND p.hora_mergulho_p = m.hora_mergulho_m
    AND m.cod_pacote_m    = pac.cod_pacote;

/*------------------- QUESTÃO 4 --------------------------------*/
DELETE FROM participante p
  USING mergulho m,
        pacote pac,
        local l
  WHERE p.cod_pacote_p     = m.cod_pacote_m
    AND p.data_mergulho_p  = m.data_mergulho_m
    AND p.hora_mergulho_p  = m.hora_mergulho_m
    AND m.cod_pacote_m     = pac.cod_pacote
    AND pac.local_mergulho = l.cod_local
    AND l.nome_local       = 'TRINDADE';
	
/*-------------------- QUESTÃO 5 --------------------------------*/
UPDATE pacote p
  SET valor_pacote = p.valor_pacote * 1.15
  FROM tipo_mergulho t
  WHERE p.cod_tipo_mergulho_p = t.cod_tipo_mergulho
    AND t.nome_tipo_mergulho IN ('Especial', 'Super Especial', 'Caverna');