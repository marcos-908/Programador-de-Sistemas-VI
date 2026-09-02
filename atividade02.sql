CREATE TABLE alunos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100),
    idade INT,
    cidade VARCHAR(50),
    curso VARCHAR(50),
    nota NUMERIC(4,2)
);

INSERT INTO alunos (nome, idade, cidade, curso, nota) VALUES
('Ana Silva', 18, 'Curitiba', 'Programação', 8.5),
('Bruno Santos', 21, 'Londrina', 'Redes', 7.0),
('Carlos Souza', 19, 'Curitiba', 'Programação', 9.0),
('Daniel Oliveira', 25, 'Maringá', 'Banco de Dados', 6.5),
('Eduarda Lima', 20, 'Curitiba', 'Redes', 8.0),
('Felipe Costa', 17, 'Londrina', 'Programação', 5.5),
('Gabriela Alves', 22, 'Maringá', 'Banco de Dados', 9.5),
('Henrique Rocha', 19, 'Curitiba', 'Redes', 7.5),
('Isabela Martins', 20, 'Londrina', 'Programação', 8.8),
('João Pereira', 23, 'Curitiba', 'Banco de Dados', 6.0),
('Karen Mendes', 18, 'Maringá', 'Programação', 9.2),
('Lucas Ferreira', 26, 'Curitiba', 'Redes', 7.8);

select * from alunos;
select nome, idade, curso from alunos;
select nome, cidade from alunos;
select nome, idade + 1 as idade_furuta from alunos;
select * from alunos where idade >= 18;
select * from alunos where cidade = 'Curitiba';
select * from alunos where nota > 8;
select * from alunos where not cidade = 'Curitiba';
select * from alunos where idade >= 18 and curso = 'Programação';
select * from alunos where cidade = 'Curitiba' or cidade = 'Londrina';
select * from alunos where nota >= 8 and cidade = 'Curitiba';
select * from alunos where idade between 18 and 20;
select * from alunos where nota between 7 and 9;
select * from alunos where curso in('Programação', 'Redes');
select * from alunos where cidade in('Curitiba', 'Londrina', 'Maringá');
select * from alunos where nome like 'A%';
select * from alunos where nome like '%a';
select * from alunos where nome ilike 'ana%';
select * from alunos where nome ilike 'c%';
select distinct cidade from alunos;
select distinct curso from alunos;
select * from alunos order by nome asc;
select * from alunos order by nota desc;
select * from alunos order by idade asc;
select * from alunos order by cidade asc, nome asc;
select * from alunos limit 5;
select * from alunos order by nota desc limit 3;
select * from alunos order by nota desc limit 3 offset 3;
select count(*) nome from alunos;
select count(*) from alunos where curso = 'Programação';
select avg(nota) from alunos;
select max(nota) from alunos;
select min(nota) from alunos;
select sum(nota) from alunos;
select min(nota) as menor,
max(nota) as maior,
avg(nota) as media
from alunos;
select cidade, count(*) as quantidade from alunos group by cidade;
select curso, count(*) as quantidade from alunos group by curso;
select cidade, avg(nota) as media from alunos group by cidade;
select curso, max(nota) as nota from alunos group by curso;
select cidade, count(*) as quantidade from alunos group by cidade having count(*) >= 3;
select curso, count(*) as quantidade from alunos group by curso having count(*) > 3;
select curso, avg(nota) as media from alunos group by curso having avg(nota) > 7;
select cidade, count(*) as alunos, avg(nota) as media from alunos group by cidade having count(*) >= 3 and avg(nota) > 7 order by avg(nota) desc;