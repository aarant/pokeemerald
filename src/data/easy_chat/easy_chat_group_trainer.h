const u8 gEasyChatWord_IChooseYou[] = _E("I CHOOSE YOU");
const u8 gEasyChatWord_Gotcha[] = _E("GOTCHA");
const u8 gEasyChatWord_Trade[] = _E("TRADE");
const u8 gEasyChatWord_Sapphire[] = _E("SAPPHIRE");
const u8 gEasyChatWord_Evolve[] = _E("EVOLVE");
const u8 gEasyChatWord_Encyclopedia[] = _E("ENCYCLOPEDIA");
const u8 gEasyChatWord_Nature[] = _E("NATURE");
const u8 gEasyChatWord_Center[] = _E("CENTER");
const u8 gEasyChatWord_Egg[] = _E("EGG");
const u8 gEasyChatWord_Link[] = _E("LINK");
const u8 gEasyChatWord_SpAbility[] = _E("SP. ABILITY");
const u8 gEasyChatWord_Trainer[] = _E("TRAINER");
const u8 gEasyChatWord_Version[] = _E("VERSION");
const u8 gEasyChatWord_Pokenav[] = _E("POKé{}NAV");
const u8 gEasyChatWord_Pokemon[] = _E("POKéMON");
const u8 gEasyChatWord_Get[] = _E("GET");
const u8 gEasyChatWord_Pokedex[] = _E("POKéDEX");
const u8 gEasyChatWord_Ruby[] = _E("RUBY");
const u8 gEasyChatWord_Level[] = _E("LEVEL");
const u8 gEasyChatWord_Red[] = _E("RED");
const u8 gEasyChatWord_Green[] = _E("GREEN");
const u8 gEasyChatWord_Bag[] = _E("BAG");
const u8 gEasyChatWord_Flame[] = _E("FLAME");
const u8 gEasyChatWord_Gold[] = _E("GOLD");
const u8 gEasyChatWord_Leaf[] = _E("LEAF");
const u8 gEasyChatWord_Silver[] = _E("SILVER");
const u8 gEasyChatWord_Emerald[] = _E("EMERALD");

const struct EasyChatWordInfo gEasyChatGroup_Trainer[] = {
    [EC_INDEX(EC_WORD_I_CHOOSE_YOU)] =
    {
        .text = gEasyChatWord_IChooseYou,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BAG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOTCHA)] =
    {
        .text = gEasyChatWord_Gotcha,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CENTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRADE)] =
    {
        .text = gEasyChatWord_Trade,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EGG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAPPHIRE)] =
    {
        .text = gEasyChatWord_Sapphire,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EMERALD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLVE)] =
    {
        .text = gEasyChatWord_Evolve,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENCYCLOPEDIA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENCYCLOPEDIA)] =
    {
        .text = gEasyChatWord_Encyclopedia,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVOLVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURE)] =
    {
        .text = gEasyChatWord_Nature,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CENTER)] =
    {
        .text = gEasyChatWord_Center,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EGG)] =
    {
        .text = gEasyChatWord_Egg,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOLD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LINK)] =
    {
        .text = gEasyChatWord_Link,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOTCHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SP_ABILITY)] =
    {
        .text = gEasyChatWord_SpAbility,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GREEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAINER)] =
    {
        .text = gEasyChatWord_Trainer,
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_CHOOSE_YOU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERSION)] =
    {
        .text = gEasyChatWord_Version,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEAF),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKENAV)] =
    {
        .text = gEasyChatWord_Pokenav,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEVEL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEMON)] =
    {
        .text = gEasyChatWord_Pokemon,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LINK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GET)] =
    {
        .text = gEasyChatWord_Get,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEDEX)] =
    {
        .text = gEasyChatWord_Pokedex,
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEDEX),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUBY)] =
    {
        .text = gEasyChatWord_Ruby,
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEMON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEVEL)] =
    {
        .text = gEasyChatWord_Level,
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKENAV),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RED)] =
    {
        .text = gEasyChatWord_Red,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RED),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GREEN)] =
    {
        .text = gEasyChatWord_Green,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUBY),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_BAG)] =
    {
        .text = gEasyChatWord_Bag,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAPPHIRE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLAME)] =
    {
        .text = gEasyChatWord_Flame,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SILVER),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GOLD)] =
    {
        .text = gEasyChatWord_Gold,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SP_ABILITY),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_LEAF)] =
    {
        .text = gEasyChatWord_Leaf,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRADE),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_SILVER)] =
    {
        .text = gEasyChatWord_Silver,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAINER),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_EMERALD)] =
    {
        .text = gEasyChatWord_Emerald,
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERSION),
        .enabled = TRUE,
    },
};
