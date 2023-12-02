import { Request, Response, NextFunction } from 'express';

export function handleNotFound(req: Request, res: Response, next: NextFunction) {
  res.status(404).json({ msg: `Cannot ${req.method} ${req.url}` });
  next();
}

export function handleInternalErrors(err: unknown, req: Request, res: Response, next: NextFunction) {
  res.status(500).json({ msg: 'Internal server error' });
  next(err);
}
