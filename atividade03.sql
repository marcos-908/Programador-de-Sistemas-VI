CREATE TABLE cursos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    carga_horaria INT NOT NULL
);

CREATE TABLE alunos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    idade INT,
    cidade VARCHAR(50),
    curso_id INT,
    FOREIGN KEY (curso_id) REFERENCES cursos(id)
);

CREATE TABLE alunos_antigos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cidade VARCHAR(50)
);

INSERT INTO cursos (nome, carga_horaria) VALUES
('Programação de Sistemas', 1200),
('Redes de Computadores', 1000),
('Banco de Dados', 800),
('Desenvolvimento Web', 1000),
('Internet das Coisas', 600),
('Eletrônica', 800);

INSERT INTO alunos (nome, idade, cidade, curso_id) VALUES
('Ana Silva', 18, 'Curitiba', 1),
('Bruno Santos', 21, 'Londrina', 2),
('Carlos Souza', 19, 'Curitiba', 1),
('Daniel Oliveira', 25, 'Maringá', 3),
('Eduarda Lima', 20, 'Curitiba', 2),
('Felipe Costa', 17, 'Londrina', 1),
('Gabriela Alves', 22, 'Maringá', 3),
('Henrique Rocha', 19, 'Curitiba', 2),
('Isabela Martins', 20, 'Londrina', 1),
('João Pereira', 23, 'Curitiba', 3),
('Karen Mendes', 18, 'Maringá', NULL),
('Lucas Ferreira', 26, 'Curitiba', 2);

INSERT INTO alunos_antigos (nome, cidade) VALUES
('Marcos Lima', 'Curitiba'),
('Patrícia Souza', 'Londrina'),
('Rafael Costa', 'Maringá'),
('Ana Silva', 'Curitiba'),
('Carlos Souza', 'Curitiba');

select * from alunos;
select nome, cidade from alunos;
select * from alunos where cidade = 'Curitiba';
select * from alunos where idade >= 20;
select alunos.nome, cursos.nome from alunos inner join cursos on alunos.curso_id = cursos.id;
select alunos.nome, alunos.idade, cursos.nome from alunos inner join cursos on alunos.curso_id = cursos.id;
select alunos.nome, alunos.cidade, cursos.nome, cursos.carga_horaria from alunos inner join cursos on alunos.curso_id = cursos.id;
select a.nome, a.cidade, c.nome, c.carga_horaria from alunos as a inner join cursos as c on a.curso_id = c.id;
select a.nome, a.cidade, c.nome from alunos as a inner join cursos as c on a.curso_id = c.id where c.nome = 'Programação de Sistemas';
select a.nome, c.nome, c.carga_horaria from alunos as a inner join cursos as c on a.curso_id = c.id where carga_horaria > 900;
select a.nome, c.nome from alunos as a left join cursos as c on a.curso_id = c.id;
select a.nome, a.cidade, c.nome from alunos as a left join cursos as c on a.curso_id = c.id;
select a.nome, c.nome from alunos as a left join cursos as c on a.curso_id = c.id where c.id is null;
select a.nome, a.cidade, c.nome from alunos as a left join cursos as c on a.curso_id = c.id where cidade = 'Curitiba';
select a.nome, c.nome from alunos as a right join cursos as c on a.curso_id = c.id;
select a.nome, c.nome, c.carga_horaria from alunos as a right join cursos as c on a.curso_id = c.id;
select nome from alunos union select nome from alunos_antigos;
select nome, cidade from alunos union select nome, cidade from alunos_antigos;
select nome from alunos union select nome from alunos_antigos order by nome asc;
select nome from alunos union all select nome from alunos_antigos;
select a.nome, a.cidade, c.nome from alunos as a inner join cursos as c on a.curso_id = c.id where cidade = 'Curitiba';
select a.nome, a.cidade from alunos as a left join cursos as c on a.curso_id = c.id where c.id is null;
select c.nome, c.carga_horaria from alunos as a right join cursos as c on a.curso_id = c.id where curso_id is null;
select nome from alunos union select nome from alunos_antigos;
select nome from alunos union all select nome from alunos_antigos;
select a.nome, a.cidade, c.nome, c.carga_horaria from alunos as a left join cursos as c on a.curso_id = c.id order by a.nome asc;