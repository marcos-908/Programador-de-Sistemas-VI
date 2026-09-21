create table Dimensoes (
	id serial primary key,
	nome varchar(50)
);

create table Registro_de_Vida (
	id serial primary key,
	nome varchar(100),
	Omega numeric(5, 3),
	id_dimensao int,
	foreign key (id_dimensao) references Dimensoes(id)
);

insert into Dimensoes (nome) values
('C875'),
('C774'),
('C999'),
('C321');

insert into Registro_de_Vida (nome, Omega, id_dimensao) values
('Douglas Gabriel Ribeiro Avila', 0.742, 1),
('Douglas Ribeiro Avila', 0.531, 1),
('Douglas G.Ribeiro Avila', 0.864, 2),
('Igor Antonio De Almeida', 0.425, 1),
('Igor Almeida', 0.782, 2),
('Igor Antonio Almeida', 0.316, 2),
('João Gabriel Alves Garlet', 0.653, 1),
('João Gabriel Garlet', 0.287, 2),
('João G. Alves Garlet', 0.915, 3),
('Luiz Carlos Vescovi', 0.478, 2),
('Luiz Vescovi', 0.694, 1),
('Luiz C. Carlos Vescovi', 0.352, 4),
('Marcos Samuel Rodrigues', 0.821, 1),
('Marcos Rodrigues', 0.264, 2),
('Marcos S. Rodrigues', 0.573, 3),
('Nicolas Gabriel Marchi Ferreira', 0.391, 2),
('Nicolas Marchi Ferreira', 0.728, 1),
('Nicolas Gabriel Ferreira', 0.612, 4),
('Ana Cristina Souza', 0.452, 1),
('Fernanda Oliveira', 0.537, 2),
('Acassio Pereira', 0.683, 3),
('Ariel Santos', 0.349, 4),
('Gabriel Alves', 0.771, 1),
('Marcos Antonio', 0.498, 2);

select r.nome, round(r.omega * 1.618, 3) as N, d.nome from Registro_de_Vida as r inner join Dimensoes as d on r.id_dimensao = d.id
where (r.nome like '%Douglas%'
or r.nome like '%Igor%'
or r.nome like '%João%'
or r.nome like '%Luiz%'
or r.nome like '%Marcos%'
or r.nome like '%Nicolas%')
and d.nome = 'C875' or d.nome = 'C774'
order by omega asc;