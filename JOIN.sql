create table alunos (
	id serial primary key,
	nome varchar(100),
	idade int,
	nota decimal (4,2)
);

create table curso (
	id serial primary key,
	curso varchar(100),
	aluno_curso int,
	foreign key (aluno_curso) references alunos(id)
);

insert into alunos(nome, idade, nota) values
('Robson', 19, 8.5),
('Aline', 18, 6.7),
('Everton', 20, 8.9),
('Erick', 16, 7.8);

insert into curso(curso, aluno_curso) values
('Programação', 3),
('Programação', 2),
('Python', 1);

insert into curso(curso, aluno_curso) values
('Robótica', NULL);

select * from alunos;
select * from curso;
select a.nome, c.curso from alunos as a inner join curso as c on a.id = c.aluno_curso;
select a.nome, c.curso from alunos as a left join curso as c on a.id = c.aluno_curso;
select a.nome, c.curso from alunos as a right join curso as c on a.id = c.aluno_curso;
select a.nome, a.nota, c.curso from alunos as a inner join curso as c on a.id = c.aluno_curso where nota >= 8.0;