import { NextFunction, Request, Response } from 'express';
import { verify } from 'jsonwebtoken';
import { getUserWithId, type User } from '../services/user.service.js';

export interface AuthRequest extends Request {
  user?: User
}

export async function verifyToken(req: AuthRequest, res: Response, next: NextFunction) {
  const header = req.headers.authorization?.split(' ');

  if (!header || !header[1]) {
    return res.status(401).json({ msg: 'No token, authorization denied' });
  }
  if (header[0] !== 'Bearer') {
    return res.status(401).json({ msg: 'Token is not valid' });
  }

  if (!process.env.SECRET)
    throw new Error("Missing SECRET environment variable");

  try {
    const decoded = verify(header[1], process.env.SECRET);
    const id = (decoded as { id: string }).id;

    req.user = await getUserWithId(id);
    if (!req.user) throw new Error();

    next();
  } catch (err) {
    return res.status(401).json({ msg: 'Token is not valid' });
  }
}
