const { exec, spawn } = require('child_process');
const { setTimeout: sleep } = require('timers/promises');

let cliOutput = '';
let serverOutput = '';
let lastUuidv4 = {};
let exitCode = 0;
let currentTest;

/********************************** TESTS SIDE ***************************************** */

const tests = [
    {
        name: 'Login',
        command: '/login "alex"',
        server_expected: 'User [[uuid]] logged in.',
        client_expected: 'Client [[uuid]] logged in with login alex',
        uuid_name_to_store: ['login_alex'],
        uuidv4_to_replace: [],
    },
    {
        name: 'Send message',
        command: '/send "{{uuidv4}}" "Hello, world!"',
        server_expected: 'Private message [[uuid]]->[[uuid]]: Hello, world!',
        client_expected: 'New private message from [[uuid]]: [Hello, world!]',
        uuidv4_to_replace: ['login_alex'],
        uuid_name_to_store: [],
    },
    {
        name: 'Get messages',
        command: '/messages "{{uuidv4}}"',
        server_expected: null,
        client_expected: 'Hello, world!',
        uuidv4_to_replace: ['login_alex'],
        uuid_name_to_store: []
    },
    {
        name: 'Login with same username',
        command: '/login "alex"',
        server_expected: 'User [[uuid]] logged out.\nUser [[uuid]] logged in.',
        client_expected: 'Client [[uuid]] logged out with login alex\nClient [[uuid]] logged in with login alex',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
    {
        name: 'Login with diffrent username',
        command: '/login "adam"',
        server_expected: 'User [[uuid]] logged out.\nNew user: adam ([[uuid]]).\nUser [[uuid]] logged in.',
        client_expected: 'Client [[uuid]] logged out with login alex\nClient [[uuid]] logged in with login adam',
        uuid_name_to_store: ['login_alex', 'login_adam'],
        uuidv4_to_replace: [],
    },
    {
        name: 'List logged users',
        command: '/users',
        server_expected: null,
        client_expected: 'User "adam" ([[uuid]]): 1\nUser "alex" ([[uuid]]): 0',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
    {
        name: 'Create team',
        command: '/create "2027 Team" "wow"',
        server_expected: 'User [[uuid]] created Team "2027 Team" ([[uuid]]).',
        client_expected: '[Team [[uuid]]] Created 2027 Team, wow\nNew team created event id [[uuid]]: 2027 Team (wow)',
        uuid_name_to_store: ['team_id'],
        uuidv4_to_replace: [],
    },
    {
        name: 'Subscribe to team',
        command: '/subscribe "{{uuidv4}}"',
        server_expected: 'User [[uuid]] subscribed to [[uuid]].',
        client_expected: '[Subscribed] [[uuid]] to [[uuid]]',
        uuid_name_to_store: [],
        uuidv4_to_replace: ['team_id'],
    },
    {
        name: 'List teams',
        command: '/list',
        server_expected: null,
        client_expected: 'Team "2027 Team" ([[uuid]]): wow',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
    {
        name: 'Use team',
        command: '/use "{{uuidv4}}"',
        server_expected: null,
        client_expected: null,
        uuid_name_to_store: [],
        uuidv4_to_replace: ['team_id'],
    },
    {
        name: 'Info team',
        command: '/info',
        server_expected: null,
        client_expected: 'Team "2027 Team" ([[uuid]]): wow',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
    {
        name: 'Create channel',
        command: '/create "MyChannel" "First!"',
        server_expected: 'Channel "MyChannel" ([[uuid]]) created in team [[uuid]].',
        client_expected: '[Channel [[uuid]]] Created MyChannel, First!\nNew channel created event id [[uuid]]: MyChannel (First!)',
        uuid_name_to_store: ['channel_id'],
        uuidv4_to_replace: [],
    },
    {
        name: 'List channels',
        command: '/list',
        server_expected: null,
        client_expected: 'Channel "MyChannel" ([[uuid]]): First!',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
    {
        name: 'Use channel',
        command: '/use "{{uuidv4}}" "{{uuidv4}}"',
        server_expected: null,
        client_expected: null,
        uuid_name_to_store: [],
        uuidv4_to_replace: ['team_id', 'channel_id'],
    },
    {
        name: 'Info channel',
        command: '/info',
        server_expected: null,
        client_expected: 'Channel "MyChannel" ([[uuid]]): First!',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
    {
        name: 'Create thread',
        command: '/create "Thread" "omg"',
        server_expected: 'New thread [[uuid]] in channel [[uuid]].\nNew reply in thread Thread ([[uuid]]) from [[uuid]]: omg',
        client_expected: 'New thread created event id [[uuid]] by ([[uuid]]) at',
        uuid_name_to_store: ['thread_id'],
        uuidv4_to_replace: [],
    },
    {
        name: 'List thread',
        command: '/list',
        server_expected: null,
        client_expected: '[Thread [[uuid]]] Created by [[uuid]]',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
    {
        name: 'Use thread',
        command: '/use "{{uuidv4}}" "{{uuidv4}}" "{{uuidv4}}"',
        server_expected: null,
        client_expected: null,
        uuid_name_to_store: [],
        uuidv4_to_replace: ['team_id', 'channel_id', 'thread_id'],
    },
    {
        name: 'Info thread',
        command: '/info',
        server_expected: null,
        client_expected: 'Thread "[[uuid]]" created by [[uuid]]',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
    {
        name: 'Create reply',
        command: '/create "Replyy"',
        server_expected: 'New reply in thread ([[uuid]]) from [[uuid]]: Replyy',
        client_expected: 'New reply from [[uuid]] in thread [[uuid]] of team [[uuid]]: [Replyy]',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
    {
        name: 'List teams subscribed',
        command: '/subscribed',
        server_expected: null,
        client_expected: 'Team "2027 Team" ([[uuid]]): wow',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
    {
        name: 'List users subscribed to a team',
        command: '/subscribed "{{uuidv4}}"',
        server_expected: null,
        client_expected: 'User "adam" ([[uuid]]): 1',
        uuid_name_to_store: [],
        uuidv4_to_replace: ['team_id'],
    },
    {
        name: 'Unsubscribe from team',
        command: '/unsubscribe "{{uuidv4}}"',
        server_expected: 'User [[uuid]] unsubscribe from [[uuid]].',
        client_expected: '[Unsubscribed] [[uuid]] to [[uuid]]',
        uuid_name_to_store: [],
        uuidv4_to_replace: ['team_id'],
    },
    {
        name: 'Check specific user (disconnected)',
        command: '/user "{{uuidv4}}"',
        server_expected: null,
        client_expected: 'User "alex" ([[uuid]]): 0',
        uuid_name_to_store: [],
        uuidv4_to_replace: ['login_alex'],
    },
    {
        name: 'Logout',
        command: '/logout',
        server_expected: 'User [[uuid]] logged out.',
        client_expected: 'Client [[uuid]] logged out with login adam',
        uuid_name_to_store: [],
        uuidv4_to_replace: [],
    },
];

/********************************** TESTS SIDE ***************************************** */

function startServer(port) {
    console.log(`Starting server on port ${port}`);
    return spawn('./myteams_server', [port], {
        env: { LD_LIBRARY_PATH: './libs/myteams' }
    });
}

function startClient(host, port) {
    return spawn('./myteams_cli', [host, port], {
        env: { LD_LIBRARY_PATH: './libs/myteams' }
    });
}

const serverPort = Math.floor(Math.random() * 10000) + 10000;
const server = startServer(serverPort);

server.stdout.on('data', (data) => {
    console.log(`[SERVER DEBUG] : ${data}`);
});

server.stderr.on('data', (data) => {
    console.error(`[SERVER LIB] : \n${data}`);
    serverOutput += data.toString();
});

server.on('close', (code) => {
    console.log(`Server exited with code ${code}`);
});

setTimeout(async () => {
    const clientHost = '127.0.0.1';
    const client = startClient(clientHost, serverPort);

    client.stdout.on('data', (data) => {
        console.log(`[CLI DEBUG] : ${data}`);
    });

    client.stderr.on('data', (data) => {
        console.error(`[CLI LIB] :\n${data}`);
        cliOutput += data.toString();
    });

    client.on('close', (code) => {
        console.log(`Client closed with code ${code}`);
    });

    await sleep(2000);

    for (const test of tests) {
        cliOutput = '';
        serverOutput = '';
        console.log(`\x1b[35mRunning test: ${test.name}\x1b[0m`);
        currentTest = test;
        for (let i = 0; i < test.uuidv4_to_replace.length; i++) {
            test.command = test.command.replace(`{{uuidv4}}`, lastUuidv4[test.uuidv4_to_replace[i]]);
        }
        client.stdin.write(`${test.command}\n`);

        await sleep(2000);

        const uuidv4 = [...cliOutput.toString().matchAll(/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/g)];
        if (uuidv4 && currentTest && currentTest.uuid_name_to_store.length > 0)
            for (let i = 0; i < currentTest.uuid_name_to_store.length; i++) {
                if (!uuidv4[i]) {
                    console.error(`\x1b[31mCould not find uuidv4 for test: ${currentTest.name}\x1b[0m`);
                    exitCode = 1;
                    break;
                }
                lastUuidv4[currentTest.uuid_name_to_store[i]] = uuidv4[i][0];
            }

        if (test.server_expected) {
            if (!serverOutput.toString().replaceAll(/([0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12})/g, '[[uuid]]').includes(test.server_expected)) {
                console.error(`\x1b[31mServer output does not match expected output for test: ${test.name}\x1b[0m`);
                console.error(`Expected: ${test.server_expected}`);
                console.error(`Actual: ${serverOutput}\n`);
                exitCode = 1;
            } else {
                console.log(`\x1b[32mTest: ${test.name} passed server side!\x1b[0m`);
            }
        }

        if (test.client_expected) {
            if (!cliOutput.toString().replaceAll(/([0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12})/g, '[[uuid]]').includes(test.client_expected)) {
                console.error(`\n\x1b[31mClient output does not match expected output for test: ${test.name}\x1b[0m`);
                console.error(`Expected: ${test.client_expected} `);
                console.error(`Actual: ${cliOutput} \n\n`);
                exitCode = 1;
            } else {
                console.log(`\x1b[32mTest: ${test.name} passed client side!\x1b[0m\n`);
            }
        }
        await sleep(1500);
    }

    currentTest = null;
    server.kill();

    await sleep(1000);
    console.log(exitCode ? 'Tests failed' : 'Tests passed');
    process.exit(exitCode);


}, 2000);
