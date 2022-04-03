create table cliente (
	cod_cliente serial not null,
	nome_cliente varchar(40) not null,
	constraint pk_cliente
		primary key (cod_cliente)
);

create or replace function clientes_vip ()
	returns table (cod_cliente integer, nome VARCHAR(40))
	as
		'select cod_cliente as c_cliente,
			nome_cliente
			from cliente;'
	language 'sql';

DROP FUNCTION clientes_vip();
	
insert into cliente (nome_cliente) values ('fulano');

select * from cliente;

select * from clientes_vip ();