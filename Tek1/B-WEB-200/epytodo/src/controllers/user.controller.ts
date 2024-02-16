import { Response, NextFunction } from 'express';
import { badParameter, notFound } from '../utils/response.js';
import * as userService from '../services/todo.service.js';
import { AuthRequest } from '../middlewares/auth.middleware.js';

export async function getUserTodos(req: AuthRequest, res: Response, next: NextFunction) {
    try {
        const user = req.user ?? null;
        if (!user) return badParameter(res);
        const todos = await userService.getUserTodos(user.id.toString());
        if (!todos) return notFound(res);
        return res.status(200).json(todos);
    } catch (error) {
        next(error);
    }
}

export async function getUserInfo(req: AuthRequest, res: Response, next: NextFunction) {
    try {
        const user = req.user ?? null;
        if (!user) return notFound(res);
        return res.status(200).json(user);
    } catch (error) {
        next(error);
    }
}
