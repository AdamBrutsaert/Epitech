import dotenv from 'dotenv';
import { Client, Collection, GatewayIntentBits } from 'discord.js';
import { loadCommands, loadEvents } from './loader/files.js';

dotenv.config();

const client = new Client({
    intents: [
        GatewayIntentBits.Guilds,
        GatewayIntentBits.GuildMessages,
        GatewayIntentBits.MessageContent,
        GatewayIntentBits.GuildMembers
    ]
});
client.interactions = new Collection();

loadCommands(client);
loadEvents(client);

client.login(process.env.BOT_TOKEN);
