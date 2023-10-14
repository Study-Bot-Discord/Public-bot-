require('dotenv').config();
const { Intents, Client, Collection, RoleManager } = require("discord.js");
const allIntents = [
    Intents.FLAGS.GUILDS,
    Intents.FLAGS.GUILD_MESSAGES,
    Intents.FLAGS.GUILD_MEMBERS,
    Intents.FLAGS.GUILD_VOICE_STATES,
    Intents.FLAGS.GUILD_BANS,
    Intents.FLAGS.GUILD_INVITES,
    Intents.FLAGS.GUILD_WEBHOOKS,
    Intents.FLAGS.GUILD_SCHEDULED_EVENTS,
    Intents.FLAGS.GUILD_MESSAGE_REACTIONS,
    Intents.FLAGS.DIRECT_MESSAGES,
    Intents.FLAGS.DIRECT_MESSAGE_TYPING,
    Intents.FLAGS.DIRECT_MESSAGE_REACTIONS
]
const client = new Client({ intents: allIntents, partials: ['MESSAGE', 'CHANNEL', 'GUILD_MEMBER', 'REACTION', 'USER'] });
const features = require("./src/Features/load-features");
const commands = require("./src/Commands/load-commands");
const globalSlash = require("./src/Global-slash-Cmds/load-slash");
const mongo = require("./src/utils/mongo");
const Global = require("./src/utils/Slash-Integration");
const PandaCMD = require("./The pandamonium/Commands/load-commands");
const PandaFeature = require("./The pandamonium/Features/load-Features");

client.commands = new Collection();

features(client);
commands(client);
globalSlash(client);
Global(client);
PandaCMD(client);
PandaFeature(client);

client.on('ready', async () => {
    await mongo();
    console.log(`Checking Mongo`);
    client.user.setActivity(`Working on my logic!!`);
    client.user.setStatus('online');
});

console.log(`Bot is online`);
client.login(process.env.TOKEN);

// Main Bot Token = NzkwNTAzMTk1NjIwNjcxNDk4.X-BjeA.4SDiHHlur2HSgXAlzLE9rlv6dtc

// TOKEN=Nzg4NTA0Mzk4OTEyMjkwODg3.GUoPhM.3setqgDtNHkeOJgQ8DF7ke2nOAWfmPOtr9GgsE
