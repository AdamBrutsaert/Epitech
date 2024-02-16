import { createConnection } from "mysql2/promise";
import dotenv from 'dotenv';

dotenv.config();

const connection = await createConnection({
    host: process.env.MYSQL_HOST,
    user: process.env.MYSQL_USER,
    password: process.env.MYSQL_ROOT_PASSWORD,
    database: process.env.MYSQL_DATABASE
}).then((connection) => {
    console.log('Connected to database');
    return connection;
}).catch((error) => {
    console.error(error);
});

export default connection;
