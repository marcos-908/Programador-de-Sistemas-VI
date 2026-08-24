CREATE TABLE departamento
(
	codigo_departamento SERIAL PRIMARY KEY,
	nome varchar(100),
	area_de_atuacao varchar(100)
);

create table patrocinadores
(
	CNPJ VARCHAR(14) primary key,
	telefone_para_contato int,
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

create table palestrande
(
	id_palestrande serial primary key,
	nome_completo varchar(100),
	telefone int,
	instituicao_de_origem varchar(100),
	e_mail varchar(100)
);

create table evento_palestrande
(
	id serial primary key,
	codigo_de_identificacao int, foreign key (codigo_de_identificacao) references evento(codigo_de_identificacao),
	id_palestrande int, foreign key (id_palestrande) references palestrande(id_palestrande)
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
insert into departamento (nome, area_de_atuacao) values ('Administrativo', ' Coordenação global');
insert into departamento (nome, area_de_atuacao) values ('Financeiro', ' Fluxo de caixa');
insert into departamento (nome, area_de_atuacao) values ('Comercial', 'Vendas');
insert into departamento (nome, area_de_atuacao) values ('Marketing', 'Atração de clientes');
insert into departamento (nome, area_de_atuacao) values ('Operações',  'Entrega de serviço');
insert into departamento (nome, area_de_atuacao) values ('Logística', 'Controle de estoque');
insert into departamento (nome, area_de_atuacao) values ('Tecnologia', 'Suporte de sistemas');
insert into departamento (nome, area_de_atuacao) values ('Jurídico', 'Proteção legal');
insert into departamento (nome, area_de_atuacao) values ('Compras', 'Negociação com fornecedores');

INSERT INTO patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('12345678000199', 1198765-4321, 'São Paulo - SP', 'Inova Alimentos');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('98765432000110', 2197654-3210, 'Rio de Janeiro - RJ', 'TechPrime Sistemas');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('45678912000122', 112654321, 'Belo Horizonte - MG', 'AgroVerde Cultivos');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('23456789000133', 212543210, 'Curitiba - PR', 'Construtora Aliança');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('34567891000144', 112432109, 'Porto Alegre - RS', 'Soluções Logísticas Express');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('56789123000155', 212321098, 'Brasília - DF', 'VivaBem Saúde');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('67891234000166', 112210987, 'Salvador - BA', 'Postos Energia');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('78891234000177', 212109876, 'Recife - PE', 'Vestuário Estilo');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('89123456000188', 112098765, 'Fortaleza - CE', 'Banco Progresso');
insert into patrocinadores (cnpj, telefone_para_contato, cidade_origem, nome) values ('90123456000100', 212987654, 'Manaus - AM', 'Norte Distribuidora');

INSERT INTO evento (nome, descricao, data_realizada, carga_horaria_total) values ('Simpósio de Tecnologia', 'Palestras sobre inteligência artificial e desenvolvimento de sistemas modernos', '2026-03-15', 16);
insert into evento (nome, descricao, data_realizada, carga_horaria_total) values ('Workshop de Orçamento', 'Prática de fluxo de caixa e planejamento financeiro para iniciantes', '2026-04-10', 8);
insert into evento (nome, descricao, data_realizada, carga_horaria_total) values ('Feira de Recrutamento', 'Encontro entre estudantes universitários e grandes empresas do mercado', '2026-05-20', 12);
insert into evento (nome, descricao, data_realizada, carga_horaria_total) values ('Congresso de Logística', 'Debates sobre gestão de estoque e otimização de rotas de entrega', '2026-06-05', 24);
insert into evento (nome, descricao, data_realizada, carga_horaria_total) values ('Curso de Vendas Rápidas', 'Técnicas avançadas de negociação e prospecção de novos clientes', '2026-07-18', 6);
insert into evento (nome, descricao, data_realizada, carga_horaria_total) values ('Treinamento de Liderança', 'Desenvolvimento de habilidades de gestão de pessoas e equipes', '2026-08-12', 20);
insert into evento (nome, descricao, data_realizada, carga_horaria_total) values ('Fórum de Direito Digital', 'Análise de contratos tecnológicos e segurança jurídica na internet', '2026-09-22', 10);
insert into evento (nome, descricao, data_realizada, carga_horaria_total) values ('Semana de Marketing', 'Estratégias de divulgação de marca e atração de público alvo', '2026-10-08', 30);
insert into evento (nome, descricao, data_realizada, carga_horaria_total) values ('Jornada de Inovação', 'Oficina de criação de novos produtos e melhoria de processos', '2026-11-14', 15);
insert into evento (nome, descricao, data_realizada, carga_horaria_total) values ('Painel de Suprimentos', 'Negociação com fornecedores e controle de compras corporativas', '2026-12-01', 4);

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

INSERT INTO palestrande (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Ana Silva Souza', 11987654321, 'Universidade de São Paulo', 'ana.silva@email.com');
insert into palestrande (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Carlos Eduardo Lima', 21976543210, 'Instituto TechPrime', 'carlos.lima@email.com');
insert into palestrande (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Mariana Costa Ribeiro', 31965432109, 'Centro de Negócios MG', 'mariana.costa@email.com');
insert into palestrande (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Bruno Alves Pereira', 41954321098, 'Faculdade Aliança', 'bruno.alves@email.com');
insert into palestrande (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Juliana Mendes Fonseca', 51943210987, 'Logística Brasil S/A', 'juliana.mendes@email.com');
insert into palestrande (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Ricardo Dias Gomes', 61932109876, 'Escola de Líderes DF', 'ricardo.dias@email.com');
insert into palestrande (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Camila Rocha Antunes', 71921098765, 'Faculdade de Direito BA', 'camila.rocha@email.com');
insert into palestrande (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Lucas Martins Neves', 81910987654, 'Marketing Digital Recife', 'lucas.martins@email.com');
insert into palestrande (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Beatriz Ramos Soares', 85909876543, 'Banco do Progresso', 'beatriz.ramos@email.com');
insert into palestrande (nome_completo, telefone, instituicao_de_origem, e_mail) values ('Diego Oliveira Cruz', 92998765432, 'Rede Norte Distribuidora', 'diego.oliveira@email.com');