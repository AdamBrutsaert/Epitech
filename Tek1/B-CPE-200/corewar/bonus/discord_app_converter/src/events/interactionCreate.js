const interactionCreate = (client, interaction) => {
    if (!interaction.isChatInputCommand()) return;

    const command = client.interactions.get(interaction.commandName);
    console.log(`Got command ${interaction.commandName} by ${interaction.user.tag}.`);
    if (!command) return;

    try {
        command.execute(client, interaction);
    } catch (error) {
        console.error(error);
        interaction.reply({ content: 'There was an error while executing this command!', ephemeral: true });
    }
};

export default interactionCreate;
