import { Request, Response, NextFunction } from 'express';
import dotenv from 'dotenv';
import bcrypt from 'bcryptjs';
import jwt from 'jsonwebtoken';

import { isValidEmail } from '../utils/validator.js';
import { badParameter } from '../utils/response.js';
import { getUserWithIdOrEmail } from '../services/user.service.js';
import { createUser } from '../services/user.service.js';

dotenv.config();

export async function register(req: Request, res: Response, next: NextFunction) {
  if (!req.body.email || !req.body.password || !req.body.firstname || !req.body.name
      || !isValidEmail(req.body.email)) {
    return badParameter(res);
  }

  try {
    if (await getUserWithIdOrEmail(req.body.email)) {
      return res.status(409).json({ msg: 'Account already exists' });
    }

    const password = bcrypt.hashSync(req.body.password, 10);
    const id = await createUser(req.body.email, password, req.body.firstname, req.body.name);

    if (!process.env.SECRET)
      throw new Error("Missing SECRET environment variable");

    return res.status(201).json({ token: jwt.sign({ id }, process.env.SECRET) });
  } catch (err) {
    next(err);
  }
}

export async function login(req: Request, res: Response, next: NextFunction) {
  if (!req.body.email || !req.body.password) {
    return badParameter(res);
  }

  try {
    const user = await getUserWithIdOrEmail(req.body.email);

    if (!user || !bcrypt.compareSync(req.body.password, user.password)) {
      return res.status(401).json({ msg: 'Invalid credentials' });
    }

    if (!process.env.SECRET)
      throw new Error("Missing SECRET environment variable");

    return res.status(200).json({ token: jwt.sign({ id: user.id }, process.env.SECRET) });
  } catch (err) {
    next(err);
  }
}
