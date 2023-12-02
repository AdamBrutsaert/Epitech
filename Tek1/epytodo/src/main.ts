import express from 'express';
import dotenv from 'dotenv';

import { handleNotFound, handleInternalErrors } from './middlewares/handleErrors.middleware.js'

import authRoute from './routes/auth.route.js';
import userRoute from './routes/user.route.js';
import usersRoute from './routes/users.route.js';
import todosRoute from './routes/todos.route.js';

dotenv.config();

const app = express();
const port = process.env.PORT || 3000;

app.use(express.json())
    .use('/', authRoute)
    .use('/user', userRoute)
    .use('/users', usersRoute)
    .use('/todos', todosRoute)
    .use(handleNotFound)
    .use(handleInternalErrors);

app.listen(port, () => {
    console.log(`Listening on port ${port}`);
});
