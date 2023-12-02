import { Request, Response, NextFunction } from 'express';
import bcryptjs from 'bcryptjs';
import { badParameter, notFound } from '../utils/response.js';
import * as userService from '../services/user.service.js';

export async function getUser(req: Request, res: Response, next: NextFunction) {
    if (!req.params.idOrEmail) return badParameter(res);

    try {
        const user = await userService.getUserWithIdOrEmail(req.params.idOrEmail);
        if (!user) return notFound(res);
        res.status(200).json(user);
    } catch (error) {
        next(error);
    }
}

export async function deleteUser(req: Request, res: Response, next: NextFunction) {
    if (!req.params.id) return badParameter(res);

    try {
        const user = await userService.getUserWithId(req.params.id);
        if (!user) return notFound(res);
        await userService.deleteUser(req.params.id);
        return res.status(200).json({ msg: `Successfully deleted record number: ${req.params.id}`});
    } catch (err) {
        next(err);
    }
}

export async function updateUser(req: Request, res: Response, next: NextFunction) {
    if (!req.params.id) return badParameter(res);
    if (!req.body.email && !req.body.password && !req.body.firstname && !req.body.name) return badParameter(res);

    try {
        const user = await userService.getUserWithId(req.params.id);
        if (!user) return notFound(res);

        if (req.body.password) {
            req.body.password = bcryptjs.hashSync(req.body.password, 10);
        }

        await userService.updateUser(req.params.id, req.body.email, req.body.password, req.body.firstname, req.body.name);
        return res.status(200).json({
            ...user,
            email: req.body.email ?? user.email,
            password: req.body.password ?? user.password,
            firstname: req.body.firstname ?? user.firstname,
            name: req.body.name ?? user.name,
        })
    } catch (err) {
        next(err);
    }
}
