CREATE DATABASE epytodo;

USE epytodo;

CREATE TABLE user (
  id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
  email VARCHAR(255) NOT NULL UNIQUE,
  password VARCHAR(255) NOT NULL,
  name VARCHAR(255) NOT NULL,
  firstname VARCHAR(255) NOT NULL,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE todo (
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  title VARCHAR(255) NOT NULL,
  description TEXT NOT NULL,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  due_time DATETIME NOT NULL,
  status ENUM('not started', 'todo', 'in progress', 'done') DEFAULT 'not started',
  user_id INT UNSIGNED NOT NULL,
  CONSTRAINT todo_fk1 FOREIGN KEY (user_id) REFERENCES `epytodo`.`user`(`id`)
);
