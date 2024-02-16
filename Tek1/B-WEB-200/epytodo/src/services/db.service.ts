import { ResultSetHeader, OkPacket, RowDataPacket } from 'mysql2';
import connection from '../configs/db.config.js';

type QueryResult = RowDataPacket[] | RowDataPacket[][] | OkPacket | OkPacket[] | ResultSetHeader;

export async function query<Type extends QueryResult>(sql: string, params: unknown[] | undefined) {
    if (!connection) throw new Error('You are not connected to the database');
    return (await connection.execute<Type>(sql, params))[0];
}
