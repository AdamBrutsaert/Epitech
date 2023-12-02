import { ActivityType, PresenceUpdateStatus, REST, Routes } from "discord.js";

const ready = (client) => {
    console.log(`Logged in as ${client.user.tag}!`);

    client.user.setPresence({
        activities: [
            {
                name: '/compile',
                type: ActivityType.Watching
            }
        ],
        status: PresenceUpdateStatus.Online
    });

    const rest = new REST({ version: '10' }).setToken(process.env.BOT_TOKEN);
    rest.put(Routes.applicationCommands(process.env.BOT_ID), {
        body: client.interactions.map(interaction => interaction.commandPayload.toJSON()),
    })
        .then(() => console.log('Successfully registered application commands.'))
};

export default ready;
