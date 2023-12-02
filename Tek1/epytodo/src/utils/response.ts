import { Response } from 'express';

export function badParameter(res: Response) {
  return res.status(400).json({ msg: 'Bad parameter' });
}

export function notFound(res: Response) {
  return res.status(404).json({ msg: 'Not found' });
}
