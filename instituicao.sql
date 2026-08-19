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
	cidade_origem varchar(100)
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
)


select * from apoiar;