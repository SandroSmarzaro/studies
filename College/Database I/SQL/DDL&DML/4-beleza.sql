/*------------------------- QUESTÃO 1 -------------------------*/

CREATE TABLE pedido (
    cod_filial_p   INTEGER NOT NULL,
    cod_pedido     INTEGER NOT NULL,
    cod_cliente_p  INTEGER NOT NULL,
    data_pedido    DATE    NOT NULL,
    posicao_pedido CHAR(1) NOT NULL,
    CONSTRAINT pk_pedido 
        PRIMARY KEY (cod_filial_p, cod_pedido),
    CONSTRAINT fk_pedido_filial
        FOREIGN KEY (cod_filial_p)
        REFERENCES filial (cod_filial),
    CONSTRAINT fk_pedido_cliente 
        FOREIGN KEY (cod_cliente_p)
        REFERENCES cliente (cod_cliente)
    CONSTRAINT ck_posicao_pedido
        CHECK (posicao_pedido IN ('A', 'F'))
);

CREATE TABLE itens_pedido (
    cod_filial_ip   INTEGER      NOT NULL,
    cod_pedido_ip   INTEGER      NOT NULL,
    cod_servprod_ip INTEGER      NOT NULL,
    cpf_ip          CHAR(11)     NOT NULL,
    quantidade_ip   INTEGER      NOT NULL,
    valor_ip        NUMERIC(6,2) NOT NULL,
    CONSTRAINT pk_itens_pedido 
        PRIMARY KEY (cod_filial_ip, cod_pedido_ip, cod_servprod_ip),
    CONSTRAINT fk_itens_pedido_pedido
        FOREIGN KEY (cod_filial_ip, cod_pedido_ip)
        REFERENCES pedido (cod_filial_p, cod_pedido),
    CONSTRAINT fk_itens_pedido_catalogo_venda
        FOREIGN KEY (cod_servprod_ip)
        REFERENCES catalogo_venda (cod_servprod), 
    CONSTRAINT fk_itens_pedido_profissional
        FOREIGN KEY (cpf_ip, cod_filial_ip)
        REFERENCES profissionais (cpf, cod_filial_p)
);

/*------------------------- QUESTÃO 2 -------------------------*/

ALTER TABLE itens_pedido
    ADD COLUMN imposto_ip NUMERIC(5,2) NULL;

UPDATE itens_pedido ip
    SET imposto_ip = ip.valor_ip * 0.045;

ALTER TABLE itens_pedido
    ALTER COLUMN imposto_ip SET NOT NULL;

/*------------------------- QUESTÃO 3 -------------------------*/

UPDATE itens_pedido ip
    SET valor_ip = cv.valor_servprod
    FROM catalogo_venda cv,
        pedido p,
        profissional pr
    WHERE ip.cod_servprod_ip = cv.cod_servprod /* JOIN para catalogo do SET */
        AND ip.cod_filial_ip = p.cod_filial_p /* JOIN para PK composta de pedido para a data*/
        AND ip.cod_pedido_ip = p.cod_pedido
        AND ip.cod_filial_ip = pr.cod_filial_p /* JOIN para PK composta de profissional */
        AND ip.cpf_ip        = pr.cpf
        AND p.data_pedido    BETWEEN '2018-10-22' AND '2018-10-30'
        AND pr.tipo_vinculo  = 'T';

/*------------------------- QUESTÃO 4 -------------------------*/

BEGIN TRANSACTION;
    DELETE FROM itens_pedido ip
    USING catalogo_venda cv,
        especialidade e
    WHERE ip.cod_servprod_ip = cv.cod_servprod /* JOIN para a tabela de catalogo */
        AND cv.especialidade = e.cod_especialidade /* JOIN para obter nome da especialidade*/
        AND e.nome_especialidade LIKE 'PED%';
    
    DELETE FROM pedido p
    USING itens_pedido ip, 
        catalogo_venda cv,
        especialidade e
    WHERE p.cod_filial_p         = ip.cod_filial_ip /* JOIN para a PK composta de Itens Pedido */
        AND p.cod_pedido         = ip.cod_pedido_ip 
        AND ip.cod_servprod_ip   = cv.cod_servprod /* JOIN para tabela catalogo_venda */
        AND cv.especialidade     = e.cod_especialidade /* JOIN para tabela especialidade */
        AND e.nome_especialidade LIKE 'PED%';
COMMIT;

/*------------------------- QUESTÃO 5 -------------------------*/

UPDATE itens_pedido ip
SET valor_ip = valor_ip * 1.11
FROM pedido p,
    cliente cl,
    cidade cd,
    uf u
WHERE ip.cod_filial_ip    = p.cod_filial_p /* JOIN para a PK composta de Pedido */
    AND ip.cod_pedido_ip  = p.cod_pedido
    AND p.cod_cliente_p   = cl.cod_cliente /* JOIN de acesso a cliente */
    AND cl.cidade_cliente = cd.cod_cidade  /* JOIN de acesso a cidade */
    AND cd.uf             = u.sigla_uf     /* JOIN de acesso a nome_uf */
    AND u.nome_uf         IN ('Rio de Janeiro', 'Bahia');