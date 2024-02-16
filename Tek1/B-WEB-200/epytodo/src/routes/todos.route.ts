import { Router } from 'express';
import { getAllTodos, getTodoWithId, createTodo, updateTodo, deleteTodo } from '../controllers/todos.controller.js';
import { verifyToken } from '../middlewares/auth.middleware.js';

const router = Router();

router.get('/', verifyToken, getAllTodos);
router.get('/:id', verifyToken, getTodoWithId);
router.post('/', verifyToken, createTodo);
router.put('/:id', verifyToken, updateTodo);
router.delete('/:id', verifyToken, deleteTodo);

export default router;
