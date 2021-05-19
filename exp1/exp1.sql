
/*
    设计一个关系，使之满足2NF而不满足3NF
*/
CREATE TABLE IF NOT EXISTS student
(
ID INT(11),
department_name VARCHAR(100) NOT NULL,
department_header VARCHAR(100) NOT NULL,
PRIMARY KEY (ID)
);
show TABLES;
INSERT INTO student(ID,department_name,department_header) VALUES(01,"计算机","王三");

SELECT * 
FROM student;


/*
    设计一个关系，使之满足3NF而不满足BCNF
*/
CREATE TABLE IF NOT EXISTS book(
    ID INT(11),
    bookName VARCHAR(100),
    author VARCHAR(100),
    PRIMARY KEY (ID)
);

SHOW TABLES;

INSERT INTO book(ID,bookName,author) VALUES (1,"C++","王二");
INSERT INTO book(ID,bookName,author) VALUES (2,"C","李四");
INSERT INTO book(ID,bookName,author) VALUES (3,"Java","张三");
INSERT INTO book(ID,bookName,author) VALUES (4,"SQL","stupid");