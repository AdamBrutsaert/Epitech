import { Request, Response, NextFunction } from 'express';
import { badParameter, notFound } from '../utils/response.js';
import { isValidStatus } from '../utils/validator.js';
import * as todoService from '../services/todo.service.js';

export async function getAllTodos(req: Request, res: Response, next: NextFunction) {
    try {
        const todos = await todoService.getAllTodos();
        if (!todos) return notFound(res);
        res.status(200).json(todos);
    } catch (error) {
        next(error);
    }
}

export async function getTodoWithId(req: Request, res: Response, next: NextFunction) {
    if (!req.params.id) return badParameter(res);

    try {
        const todo = await todoService.getTodoWithId(req.params.id);
        if (!todo) return notFound(res);
        res.status(200).json(todo);
    } catch (error) {
        next(error);
    }
}

export async function createTodo(req: Request, res: Response, next: NextFunction) {
    if (!req.body.title || !req.body.description || !req.body.due_time || !req.body.user_id) return badParameter(res);
    const uid = Number.parseInt(req.body.user_id);
    const status : string = (req.body.status) ? req.body.status : "not started"
    if (Number.isNaN(uid) || !isValidStatus(status)) return badParameter(res);

    try {
        const todo = await todoService.createTodo(req.body.title, req.body.description, req.body.due_time, req.body.user_id, status);
        if (!todo) return notFound(res);
        res.status(200).json(todo);
    } catch (error) {
        next(error);
    }
}

export async function updateTodo(req: Request, res: Response, next: NextFunction) {
    if (!req.params.id) return badParameter(res);
    if (!req.body.title && !req.body.description && !req.body.due_time && !req.body.user_id && !req.body.status) return badParameter(res);

    try {
        const todo = await todoService.updateTodo(req.params.id, req.body.title, req.body.description, req.body.due_time, req.body.user_id, req.body.status);
        return (todo) ? res.status(200).json(todo) : badParameter(res);
    } catch (err) {
        next(err);
    }
}

export async function deleteTodo(req: Request, res: Response, next: NextFunction) {
    if (!req.params.id) return badParameter(res);

    try {
        if ((await todoService.deleteTodo(req.params.id)) > 0)
            return res.status(200).json({"msg": `Successfully deleted record number: ${req.params.id}`});
        else
            return notFound(res);
    } catch (err) {
        next(err);
    }
}
