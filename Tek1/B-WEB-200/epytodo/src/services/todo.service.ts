import { OkPacket, RowDataPacket } from 'mysql2';
import { badParameter } from '../utils/response.js';
import { query } from './db.service.js';

export interface Todo extends RowDataPacket {
  id: number;
  title: string;
  description: string;
  due_time: Date;
  user_id: number;
  status: string;
  created_at: Date;
}

export async function getAllTodos() {
  return (await query<Todo[]>('SELECT * FROM epytodo.todo;', []));
}

export async function getTodoWithId(id: string) {
  return (await query<Todo[]>('SELECT * FROM epytodo.todo WHERE id = ? LIMIT 1;', [id]))[0];
}

export async function createTodo(title: string, description: string, due_time: string, user_id: string, status: string) {
  return getTodoWithId((await query<OkPacket>('INSERT INTO epytodo.todo(title, description, due_time, user_id, status) VALUES(?, ?, ?, ?, ?);', [title, description, due_time, user_id, status])).insertId.toString());
}

export async function updateTodo(id: string, title: string, description: string, due_time: string, user_id: string, status: string) {
  if((await query<OkPacket>('UPDATE epytodo.todo SET title = COALESCE(?, title), description = COALESCE(?, description), due_time = COALESCE(?, due_time), user_id = COALESCE(?, user_id), status = COALESCE(?, status) WHERE id = ?;', [title ?? null, description ?? null, due_time ?? null, user_id ?? null, status ?? null, id])).affectedRows > 0)
    return getTodoWithId(id);
  else
    return null;
}

export async function deleteTodo(id: string) {
  return (await query<OkPacket>('DELETE FROM epytodo.todo WHERE id = ?;', [id])).affectedRows;
}

export async function getUserTodos(user_id: string) {
  return (await query<Todo[]>('SELECT * FROM epytodo.todo WHERE user_id = ?;', [user_id]));
}
