import { OkPacket, RowDataPacket } from 'mysql2';
import { query } from './db.service.js';

export interface User extends RowDataPacket {
  id: number;
  email: string;
  password: string;
  firstname: string;
  name: string;
  created_at: Date;
}

export async function getUserWithId(id: string) {
  return (await query<User[]>('SELECT * FROM epytodo.user WHERE id = ? LIMIT 1;', [id]))[0];
}

export async function getUserWithIdOrEmail(idOrEmail: string) {
  return (await query<User[]>('SELECT * FROM epytodo.user WHERE id = ? OR email = ? LIMIT 1;', [idOrEmail, idOrEmail]))[0];
}

export async function deleteUser(id: string) {
    await query('DELETE FROM epytodo.todo WHERE user_id = ?;', [id]);
    await query('DELETE FROM epytodo.user WHERE id = ?;', [id]);
}

export async function updateUser(
  id: string,
  email: string | undefined,
  password: string | undefined,
  firstname: string | undefined,
  name: string | undefined
) {
  await query(
    'UPDATE epytodo.user SET email = COALESCE(?, email), password = COALESCE(?, password), firstname = COALESCE(?, firstname), name = COALESCE(?, name) WHERE id=?;',
    [email ?? null, password ?? null, firstname ?? null, name ?? null, id],
  );
}

export async function createUser(email: string, password: string, firstname: string, name: string) {
  return (await query<OkPacket>('INSERT INTO epytodo.user (email, password, firstname, name) VALUES (?, ?, ?, ?);', [email, password, firstname, name])).insertId;
}
