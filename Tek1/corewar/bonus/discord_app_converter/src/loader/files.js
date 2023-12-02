import fs from 'node:fs';

const loadEvents = (client) => {
    fs.readdirSync('./src/events').filter(file => file.endsWith('.js')).forEach(async file => {
        const event = await import(`${process.cwd()}/src/events/${file}`).then(m => m.default);
        const eventName = file.split('.')[0];
        client.on(eventName, (...args) => event(client, ...args));
    });
};

const loadCommands = (client) => {
    fs.readdirSync('./src/interactions').filter(file => file.endsWith('.js')).forEach(async file => {
        const interaction = await import(`${process.cwd()}/src/interactions/${file}`).then(m => m.default);
        const interactionName = file.split('.')[0];
        client.interactions.set(interactionName, interaction);
    });
};

export { loadCommands, loadEvents };
