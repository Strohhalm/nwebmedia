CREATE TABLE nox.NOX_INF_KEYS (
	KEY_CLASS varchar(50) NOT NULL, 
    COMPONENT varchar(50) NOT NULL, 
    KEY_VALUE LONG NOT NULL,
    PRIMARY KEY (KEY_CLASS, COMPONENT));