/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** help
*/

void help(void)
{
    printf("----HELP----\n\n");
    helpCommon();
    helpCreate();
    helpList();
    helpInfo();
}

void helpCommon(void)
{
    printf("/login [“username”]: Set the username used by client.\n");
    printf("/logout: Disconnect the client from the server.\n");
    printf("/use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”]:");
    printf(" Use specify a context team/channel/thread.\n");
    printf("/help: Show help.\n");
    printf("/users: Get the list of all users that exist on the domain.\n");
    printf("/user [“user_uuid”]: Get information about a user.\n");
    printf("/send [“user_uuid”] [“message_body”]:  Send a message to a user\n");
    printf("/messages [“user_uuid”]: Send a message to a user\n");
    printf("/subscribed ?[“team_uuid”]: List all subscribed teams or list all ");
    printf(" users subscribed to a team.\n");
    printf("/subscribe [“team_uuid”]: Subscribe to the event of a team");
    printf(" and its sub directories (enable receptionof all events from a team).\n");
    printf("/unsubscribe [“team_uuid”]: Unsubscribe from a team\n");
}

void helpCreate(void)
{
    printf("/create [“team_name”] [“team_description”]: Create a new team ");
    printf("(When the context is not defined (/use)).\n");
    printf("/create [“channel_name”] [“channel_description”]: Create a new channel ");
    printf("(When team_uuid is defined (/use “team_uuid”)).\n");
    printf("/create [“thread_title”] [“thread_message”]: Create a new thread ");
    printf("(When team_uuid and channel_uuid are defined (/use “team_id” “channel_uuid”)).\n");
    printf("/create [“comment_body”]: Create a new reply ");
    printf("(When team_uuid, channel_uuid and thread_uuid are defined ");
    printf("/use “team_uuid” “channel_uuid” “thread_uuid”).\n");
}

void helpList(void)
{
    printf("/list: List all existing teams ");
    printf("When the context is not defined (/use)).\n");
    printf("/list: List all existing channels ");
    printf("(When team_uuid is defined (/use “team_uuid”)).\n");
    printf("/list: list all existing threads ");
    printf("(When team_uuid and channel_uuid are defined (/use “team_uuid”");
    printf(" “channel_uuid”)).\n");
    printf("/list: List all existing replies (When team_uuid, channel_uuid ");
    printf("and thread_uuid are defined (/use “team_uuid” “channel_uuid” ");
    printf("“thread_uuid”).\n");
}

void helpInfo(void)
{
    printf("/info: Display currently logged user infos ");
    printf("(When the context is not defined (/use)).\n");
    printf("/info: Display currently selected team infos ");
    printf("(When team_uuid is defined (/use “team_uuid”)).\n");
    printf("/info: Display currently selected channel infos ");
    printf("(When team_uuid and channel_uuid are defined ");
    printf("/use “team_uuid” “channel_uuid”)).\n");
    printf("/info: Display currently selected thread infos ");
    printf("(When team_uuid, channel_uuid and thread_uuid ");
    printf("are defined (/use “team_uuid” “channel_uuid” ");
    printf("“thread_uuid”)).\n");
}