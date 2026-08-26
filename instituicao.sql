CREATE TABLE departamento
(
	codigo_departamento SERIAL PRIMARY KEY,
	nome varchar(100),
	area_de_atuacao varchar(100)
);

create table patrocinadores
(
	CNPJ VARCHAR(14) primary key,
	telefone_para_contato VARCHAR(20),
	cidade_origem varchar(100),
	nome varchar(100)
);

CREATE TABLE evento
(
	codigo_de_identificacao SERIAL PRIMARY KEY,
	nome varchar(100),
	descricao TEXT,
	data_realizada DATE NOT NULL,
	carga_horaria_total int NOT NULL,
	codigo_departamento int, foreign key (codigo_departamento) references departamento(codigo_departamento)
);

create table apoiar
(
	codigo_de_identificacao int, foreign key (codigo_de_identificacao) references evento(codigo_de_identificacao),
	CNPJ Varchar(14), foreign key (CNPJ) references patrocinadores(CNPJ),
	primary key (codigo_de_identificacao, CNPJ)
);

create table palestrante
(
	id_palestrante serial primary key,
	nome_completo varchar(100),
	telefone VARCHAR(20),
	instituicao_de_origem varchar(100),
	e_mail varchar(100)
);

create table evento_palestrante
(
	id serial primary key,
	codigo_de_identificacao int, foreign key (codigo_de_identificacao) references evento(codigo_de_identificacao),
	id_palestrante int, foreign key (id_palestrante) references palestrante(id_palestrante)
);

create table estudante
(
	numero_matricula serial primary key,
	nome_completo varchar(100),
	periodo varchar(50),
	e_mail_institucional varchar(100) not null,
	curso varchar(100) not null
);

create table certificado
(
	id_certificado serial primary key,
	data_emissao date not null,
	carga_horaria_validada int not null
);

create table inscricao
(
	situacao_da_participacao varchar(100),
	id_certificado int, foreign key (id_certificado) references certificado(id_certificado),
	numero_matricula int, foreign key (numero_matricula) references estudante(numero_matricula),
	codigo_de_identificacao int, foreign key (codigo_de_identificacao) references evento(codigo_de_identificacao),
	data_inscricao date,
	primary key (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao)
);

create table espaco
(
	identificacao varchar(100) primary key,
	id_certificado int, foreign key (id_certificado) references certificado(id_certificado),
	codigo_de_identificacao int, foreign key (codigo_de_identificacao) references evento(codigo_de_identificacao),
	capacidade_maxima int,
	nome varchar(100)
);

INSERT INTO departamento (nome, area_de_atuacao) VALUES ('Recursos Humanos', 'Gestao de Pessoas');
insert into departamento (nome, area_de_atuacao) values ('Administrativo', 'Coordenação global');
insert into departamento (nome, area_de_atuacao) values ('Financeiro', 'Fluxo de caixa');
insert into departamento (nome, area_de_atuacao) values ('Comercial', 'Vendas');
insert into departamento (nome, area_de_atuacao) values ('Marketing', 'Atração de clientes');
insert into departamento (nome, area_de_atuacao) values ('Operações',  'Entrega de serviço');
insert into departamento (nome, area_de_atuacao) values ('Logística', 'Controle de estoque');
insert into departamento (nome, area_de_atuacao) values ('Tecnologia', 'Suporte de sistemas');
insert into departamento (nome, area_de_atuacao) values ('Jurídico', 'Proteção legal');
insert into departamento (nome, area_de_atuacao) values ('Compras', 'Negociação com fornecedores');

INSERT INTO patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('12345678000199', '1198765-4321', 'São Paulo - SP', 'Inova Alimentos');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('98765432000110', '2197654-3210', 'Rio de Janeiro - RJ', 'TechPrime Sistemas');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('45678912000122', '112654321', 'Belo Horizonte - MG', 'AgroVerde Cultivos');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('23456789000133', '212543210', 'Curitiba - PR', 'Construtora Aliança');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('34567891000144', '112432109', 'Porto Alegre - RS', 'Soluções Logísticas Express');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('56789123000155', '212321098', 'Brasília - DF', 'VivaBem Saúde');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('67891234000166', '112210987', 'Salvador - BA', 'Postos Energia');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('78891234000177', '212109876', 'Recife - PE', 'Vestuário Estilo');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('89123456000188', '112098765', 'Fortaleza - CE', 'Banco Progresso');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('90123456000100', '212987654', 'Manaus - AM', 'Norte Distribuidora');

INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total, codigo_departamento) VALUES ('Simpósio de Tecnologia', 'Palestras sobre inteligência artificial e desenvolvimento de sistemas modernos', '2026-03-15', 16, 8);
INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total, codigo_departamento) VALUES ('Workshop de Orçamento', 'Prática de fluxo de caixa e planejamento financeiro para iniciantes', '2026-04-10', 8, 3);
INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total, codigo_departamento) VALUES ('Feira de Recrutamento', 'Encontro entre estudantes universitários e grandes empresas do mercado', '2026-05-20', 12, 1);
INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total, codigo_departamento) VALUES ('Congresso de Logística', 'Debates sobre gestão de estoque e otimização de rotas de entrega', '2026-06-05', 24, 7);
INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total, codigo_departamento) VALUES ('Curso de Vendas Rápidas', 'Técnicas avançadas de negociação e prospecção de novos clientes', '2026-07-18', 6, 4);
INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total, codigo_departamento) VALUES ('Treinamento de Liderança', 'Desenvolvimento de habilidades de gestão de pessoas e equipes', '2026-08-12', 20, 1);
INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total, codigo_departamento) VALUES ('Fórum de Direito Digital', 'Análise de contratos tecnológicos e segurança jurídica na internet', '2026-09-22', 10, 9);
INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total, codigo_departamento) VALUES ('Semana de Marketing', 'Estratégias de divulgação de marca e atração de público alvo', '2026-10-08', 30, 5);
INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total, codigo_departamento) VALUES ('Jornada de Inovação', 'Oficina de criação de novos produtos e melhoria de processos', '2026-11-14', 15, 8);
INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total, codigo_departamento) VALUES ('Painel de Suprimentos', 'Negociação com fornecedores e controle de compras corporativas', '2026-12-01', 4, 10);

INSERT INTO apoiar (codigo_de_identificacao, CNPJ) values (1, '12345678000199');
insert into apoiar (codigo_de_identificacao, CNPJ) values (2, '98765432000110');
insert into apoiar (codigo_de_identificacao, CNPJ) values (3, '45678912000122');
insert into apoiar (codigo_de_identificacao, CNPJ) values (4, '23456789000133');
insert into apoiar (codigo_de_identificacao, CNPJ) values (5, '34567891000144');
insert into apoiar (codigo_de_identificacao, CNPJ) values (6, '56789123000155');
insert into apoiar (codigo_de_identificacao, CNPJ) values (7, '67891234000166');
insert into apoiar (codigo_de_identificacao, CNPJ) values (8, '78891234000177');
insert into apoiar (codigo_de_identificacao, CNPJ) values (9, '89123456000188');
insert into apoiar (codigo_de_identificacao, CNPJ) values (10, '90123456000100');

INSERT INTO palestrante (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Ana Silva Souza', '11987654321', 'Universidade de São Paulo', 'ana.silva@email.com');
insert into palestrante (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Carlos Eduardo Lima', '21976543210', 'Instituto TechPrime', 'carlos.lima@email.com');
insert into palestrante (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Mariana Costa Ribeiro', '31965432109', 'Centro de Negócios MG', 'mariana.costa@email.com');
insert into palestrante (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Bruno Alves Pereira', '41954321098', 'Faculdade Aliança', 'bruno.alves@email.com');
insert into palestrante (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Juliana Mendes Fonseca', '51943210987', 'Logística Brasil S/A', 'juliana.mendes@email.com');
insert into palestrante (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Ricardo Dias Gomes', '61932109876', 'Escola de Líderes DF', 'ricardo.dias@email.com');
insert into palestrante (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Camila Rocha Antunes', '71921098765', 'Faculdade de Direito BA', 'camila.rocha@email.com');
insert into palestrante (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Lucas Martins Neves', '81910987654', 'Marketing Digital Recife', 'lucas.martins@email.com');
insert into palestrante (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Beatriz Ramos Soares', '85909876543', 'Banco do Progresso', 'beatriz.ramos@email.com');
insert into palestrante (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Diego Oliveira Cruz', '92998765432', 'Rede Norte Distribuidora', 'diego.oliveira@email.com');

INSERT INTO evento_palestrante (codigo_de_identificacao, id_palestrante) values (1, 1);
insert into evento_palestrante (codigo_de_identificacao, id_palestrante) values (2, 2);
insert into evento_palestrante (codigo_de_identificacao, id_palestrante) values (3, 3);
insert into evento_palestrante (codigo_de_identificacao, id_palestrante) values (4, 4);
insert into evento_palestrante (codigo_de_identificacao, id_palestrante) values (5, 5);
insert into evento_palestrante (codigo_de_identificacao, id_palestrante) values (6, 6);
insert into evento_palestrante (codigo_de_identificacao, id_palestrante) values (7, 7);
insert into evento_palestrante (codigo_de_identificacao, id_palestrante) values (8, 8);
insert into evento_palestrante (codigo_de_identificacao, id_palestrante) values (9, 9);
insert into evento_palestrante (codigo_de_identificacao, id_palestrante) values (10, 10);

INSERT INTO estudante (nome_completo, periodo, e_mail_institucional, curso) values ('Ana Beatriz Silva', 'Manhã', 'ana.silva@aluno.universidade.edu.br', 'Ciência da Computação');
insert into estudante (nome_completo, periodo, e_mail_institucional, curso) values ('Lucas Gabriel Santos', 'Noite', 'lucas.santos@aluno.universidade.edu.br', 'Engenharia de Software');
insert into estudante (nome_completo, periodo, e_mail_institucional, curso) values ('Mariana Oliveira Costa', 'Tarde', 'mariana.costa@aluno.universidade.edu.br', 'Sistemas de Informação');
insert into estudante (nome_completo, periodo, e_mail_institucional, curso) values ('Mateus Henrique Souza', 'Noite', 'mateus.souza@aluno.universidade.edu.br', 'Análise e Des. de Sistemas');
insert into estudante (nome_completo, periodo, e_mail_institucional, curso) values ('Camila Rodrigues Lima', 'Manhã', 'camila.lima@aluno.universidade.edu.br', 'Engenharia de Computação');
insert into estudante (nome_completo, periodo, e_mail_institucional, curso) values ('Gabriel Alves Ferreira', 'Noite', 'gabriel.ferreira@aluno.universidade.edu.br', 'Banco de Dados');
insert into estudante (nome_completo, periodo, e_mail_institucional, curso) values ('Beatriz Rocha Pereira', 'Tarde', 'beatriz.pereira@aluno.universidade.edu.br', 'Redes de Computadores');
insert into estudante (nome_completo, periodo, e_mail_institucional, curso) values ('Rafael Barbosa Martins', 'Manhã', 'rafael.martins@aluno.universidade.edu.br', 'Segurança da Informação');
insert into estudante (nome_completo, periodo, e_mail_institucional, curso) values ('Larissa Carvalho Melo', 'Noite', 'larissa.melo@aluno.universidade.edu.br', 'Ciência da Computação');
insert into estudante (nome_completo, periodo, e_mail_institucional, curso) values ('Thiago Vinícius Ribeiro', 'Tarde', 'thiago.ribeiro@aluno.universidade.edu.br', 'Engenharia de Software');

INSERT INTO certificado (data_emissao, carga_horaria_validada) values ('2024-03-15', 40);
insert into certificado (data_emissao, carga_horaria_validada) values ('2024-04-10', 20);
insert into certificado (data_emissao, carga_horaria_validada) values ('2023-11-20', 60);
insert into certificado (data_emissao, carga_horaria_validada) values ('2024-01-08', 30);
insert into certificado (data_emissao, carga_horaria_validada) values ('2023-09-05', 45);
insert into certificado (data_emissao, carga_horaria_validada) values ('2024-02-28', 15);
insert into certificado (data_emissao, carga_horaria_validada) values ('2023-10-12', 80);
insert into certificado (data_emissao, carga_horaria_validada) values ('2024-05-02', 25);
insert into certificado (data_emissao, carga_horaria_validada) values ('2023-12-18', 50);
insert into certificado (data_emissao, carga_horaria_validada) values ('2024-06-01', 36);

INSERT INTO inscricao (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao, data_inscricao) values ('Participou', 1, 1, 1, '2024-02-10');
insert into inscricao (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao, data_inscricao) values ('Não participou', 2, 2, 2, '2024-03-01');
insert into inscricao (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao, data_inscricao) values ('Participou', 3, 3, 3, '2023-10-15');
insert into inscricao (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao, data_inscricao) values ('Participou', 4, 4, 4, '2023-12-05');
insert into inscricao (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao, data_inscricao) values ('Não participou', 5, 5, 5, '2023-08-20');
insert into inscricao (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao, data_inscricao) values ('Participou', 6, 6, 6, '2024-01-12');
insert into inscricao (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao, data_inscricao) values ('Não participou', 7, 7, 7, '2023-09-30');
insert into inscricao (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao, data_inscricao) values ('Participou', 8, 8, 8, '2024-04-18');
insert into inscricao (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao, data_inscricao) values ('Participou', 9, 9, 9, '2023-11-02');
insert into inscricao (situacao_da_participacao, id_certificado, numero_matricula, codigo_de_identificacao, data_inscricao) values ('Não participou', 10, 10, 10, '2024-05-20');

INSERT INTO espaco (identificacao, id_certificado, codigo_de_identificacao, capacidade_maxima, nome) values ('ESP-01', 1,1, 300, 'Auditório Principal');
insert into espaco (identificacao, id_certificado, codigo_de_identificacao, capacidade_maxima, nome) values ('ESP-02', 2, 2, 40, 'Laboratório de Informática 1');
insert into espaco (identificacao, id_certificado, codigo_de_identificacao, capacidade_maxima, nome) values ('ESP-03', 3, 3, 80, 'Sala de Conferências A');
insert into espaco (identificacao, id_certificado, codigo_de_identificacao, capacidade_maxima, nome) values ('ESP-04', 4, 4, 35, 'Laboratório de Hardware');
insert into espaco (identificacao, id_certificado, codigo_de_identificacao, capacidade_maxima, nome) values ('ESP-05', 5, 5, 150, 'Anfiteatro Bloco B');
insert into espaco (identificacao, id_certificado, codigo_de_identificacao, capacidade_maxima, nome) values ('ESP-06', 6, 6, 60, 'Miniauditório');
insert into espaco (identificacao, id_certificado, codigo_de_identificacao, capacidade_maxima, nome) values ('ESP-07', 7, 7, 30, 'Laboratório de Redes');
insert into espaco (identificacao, id_certificado, codigo_de_identificacao, capacidade_maxima, nome) values ('ESP-08', 8, 8, 50, 'Sala Multiuso 102');
insert into espaco (identificacao, id_certificado, codigo_de_identificacao, capacidade_maxima, nome) values ('ESP-09', 9, 9, 500, 'Centro de Eventos');
insert into espaco (identificacao, id_certificado, codigo_de_identificacao, capacidade_maxima, nome) values ('ESP-10', 10, 10, 25, 'Sala de Treinamento C');

select capacidade_maxima from espaco order by capacidade_maxima asc;