import { Router } from 'express';
import { getUserInfo, getUserTodos } from '../controllers/user.controller.js';
import { verifyToken } from '../middlewares/auth.middleware.js';

const router = Router();

router.get('/todos', verifyToken, getUserTodos);
router.get('/', verifyToken, getUserInfo);

export default router;
