import { Router } from 'express';
import { getUser, deleteUser, updateUser } from '../controllers/users.controller.js';
import { verifyToken } from '../middlewares/auth.middleware.js';

const router = Router();

router.get('/:idOrEmail', verifyToken, getUser);
router.delete('/:id', verifyToken, deleteUser);
router.put('/:id', verifyToken, updateUser);

export default router;
