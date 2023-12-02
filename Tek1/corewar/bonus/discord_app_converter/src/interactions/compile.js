import { SlashCommandBuilder } from '@discordjs/builders';
import { exec } from 'child_process';
import fetch from 'node-fetch';
import { v4 as uuidv4 } from 'uuid';
import fs from 'node:fs';

const execute = async (_, interaction) => {
    const attachment = interaction.options.getAttachment('file');
    const response = await fetch(attachment.url);
    const buffer = await response.buffer();
    const filename = uuidv4();
    const filepath = `/tmp/${filename}.s`;

    fs.writeFileSync(filepath, buffer);

    exec(`./src/assets/asm ${filepath}`, async (error, stdout, stderr) => {
        if (error)
            return interaction.reply({ content: `:x: Compilation failed:\n\`\`\`${error.message.split('\n').slice(1).join('\n')}\`\`\``});
        if (stderr)
            return interaction.reply({ content: `:x: Compilation failed:\n\`\`\`${stderr}}\`\`\``});
        await interaction.reply({ content: `:white_check_mark: Compilation successful!`, files: [{
                attachment: `/tmp/${filename}.cor`,
                name: `${attachment.name.split('.')[0]}.cor`
            }]
        });
        fs.unlinkSync(filepath);
        fs.unlinkSync(`/tmp/${filename}.cor`);
    });
}

const commandPayload = new SlashCommandBuilder()
    .setName('compile')
    .setDescription('Compiles your .s file into .cor file.')
    .addAttachmentOption(option => option.setName('file').setDescription('The .s file to compile.').setRequired(true));

export default {
    execute,
    commandPayload
};