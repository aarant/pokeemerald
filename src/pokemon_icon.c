#include "global.h"
#include "graphics.h"
#include "mail.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "sprite.h"

#define POKE_ICON_BASE_PAL_TAG 56000

#define INVALID_ICON_SPECIES SPECIES_OLD_UNOWN_J // Oddly specific, used when an icon should be a ?. Any of the 'old unown' would work

struct MonIconSpriteTemplate
{
    const struct OamData *oam;
    const u8 *image;
    const union AnimCmd *const *anims;
    const union AffineAnimCmd *const *affineAnims;
    void (*callback)(struct Sprite *);
    u16 paletteTag;
};

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *, s16, s16, u8);
static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite);

const u8 *const gMonIconTable[] =
{
    [SPECIES_NONE] = gMonIcon_Bulbasaur,
    [SPECIES_BULBASAUR] = gMonIcon_Bulbasaur,
    [SPECIES_IVYSAUR] = gMonIcon_Ivysaur,
    [SPECIES_VENUSAUR] = gMonIcon_Venusaur,
    [SPECIES_CHARMANDER] = gMonIcon_Charmander,
    [SPECIES_CHARMELEON] = gMonIcon_Charmeleon,
    [SPECIES_CHARIZARD] = gMonIcon_Charizard,
    [SPECIES_SQUIRTLE] = gMonIcon_Squirtle,
    [SPECIES_WARTORTLE] = gMonIcon_Wartortle,
    [SPECIES_BLASTOISE] = gMonIcon_Blastoise,
    [SPECIES_CATERPIE] = gMonIcon_Caterpie,
    [SPECIES_METAPOD] = gMonIcon_Metapod,
    [SPECIES_BUTTERFREE] = gMonIcon_Butterfree,
    [SPECIES_WEEDLE] = gMonIcon_Weedle,
    [SPECIES_KAKUNA] = gMonIcon_Kakuna,
    [SPECIES_BEEDRILL] = gMonIcon_Beedrill,
    [SPECIES_PIDGEY] = gMonIcon_Pidgey,
    [SPECIES_PIDGEOTTO] = gMonIcon_Pidgeotto,
    [SPECIES_PIDGEOT] = gMonIcon_Pidgeot,
    [SPECIES_RATTATA] = gMonIcon_Rattata,
    [SPECIES_RATICATE] = gMonIcon_Raticate,
    [SPECIES_SPEAROW] = gMonIcon_Spearow,
    [SPECIES_FEAROW] = gMonIcon_Fearow,
    [SPECIES_EKANS] = gMonIcon_Ekans,
    [SPECIES_ARBOK] = gMonIcon_Arbok,
    [SPECIES_PIKACHU] = gMonIcon_Pikachu,
    [SPECIES_RAICHU] = gMonIcon_Raichu,
    [SPECIES_SANDSHREW] = gMonIcon_Sandshrew,
    [SPECIES_SANDSLASH] = gMonIcon_Sandslash,
    [SPECIES_NIDORAN_F] = gMonIcon_NidoranF,
    [SPECIES_NIDORINA] = gMonIcon_Nidorina,
    [SPECIES_NIDOQUEEN] = gMonIcon_Nidoqueen,
    [SPECIES_NIDORAN_M] = gMonIcon_NidoranM,
    [SPECIES_NIDORINO] = gMonIcon_Nidorino,
    [SPECIES_NIDOKING] = gMonIcon_Nidoking,
    [SPECIES_CLEFAIRY] = gMonIcon_Clefairy,
    [SPECIES_CLEFABLE] = gMonIcon_Clefable,
    [SPECIES_VULPIX] = gMonIcon_Vulpix,
    [SPECIES_NINETALES] = gMonIcon_Ninetales,
    [SPECIES_JIGGLYPUFF] = gMonIcon_Jigglypuff,
    [SPECIES_WIGGLYTUFF] = gMonIcon_Wigglytuff,
    [SPECIES_ZUBAT] = gMonIcon_Zubat,
    [SPECIES_GOLBAT] = gMonIcon_Golbat,
    [SPECIES_ODDISH] = gMonIcon_Oddish,
    [SPECIES_GLOOM] = gMonIcon_Gloom,
    [SPECIES_VILEPLUME] = gMonIcon_Vileplume,
    [SPECIES_PARAS] = gMonIcon_Paras,
    [SPECIES_PARASECT] = gMonIcon_Parasect,
    [SPECIES_VENONAT] = gMonIcon_Venonat,
    [SPECIES_VENOMOTH] = gMonIcon_Venomoth,
    [SPECIES_DIGLETT] = gMonIcon_Diglett,
    [SPECIES_DUGTRIO] = gMonIcon_Dugtrio,
    [SPECIES_MEOWTH] = gMonIcon_Meowth,
    [SPECIES_PERSIAN] = gMonIcon_Persian,
    [SPECIES_PSYDUCK] = gMonIcon_Psyduck,
    [SPECIES_GOLDUCK] = gMonIcon_Golduck,
    [SPECIES_MANKEY] = gMonIcon_Mankey,
    [SPECIES_PRIMEAPE] = gMonIcon_Primeape,
    [SPECIES_GROWLITHE] = gMonIcon_Growlithe,
    [SPECIES_ARCANINE] = gMonIcon_Arcanine,
    [SPECIES_POLIWAG] = gMonIcon_Poliwag,
    [SPECIES_POLIWHIRL] = gMonIcon_Poliwhirl,
    [SPECIES_POLIWRATH] = gMonIcon_Poliwrath,
    [SPECIES_ABRA] = gMonIcon_Abra,
    [SPECIES_KADABRA] = gMonIcon_Kadabra,
    [SPECIES_ALAKAZAM] = gMonIcon_Alakazam,
    [SPECIES_MACHOP] = gMonIcon_Machop,
    [SPECIES_MACHOKE] = gMonIcon_Machoke,
    [SPECIES_MACHAMP] = gMonIcon_Machamp,
    [SPECIES_BELLSPROUT] = gMonIcon_Bellsprout,
    [SPECIES_WEEPINBELL] = gMonIcon_Weepinbell,
    [SPECIES_VICTREEBEL] = gMonIcon_Victreebel,
    [SPECIES_TENTACOOL] = gMonIcon_Tentacool,
    [SPECIES_TENTACRUEL] = gMonIcon_Tentacruel,
    [SPECIES_GEODUDE] = gMonIcon_Geodude,
    [SPECIES_GRAVELER] = gMonIcon_Graveler,
    [SPECIES_GOLEM] = gMonIcon_Golem,
    [SPECIES_PONYTA] = gMonIcon_Ponyta,
    [SPECIES_RAPIDASH] = gMonIcon_Rapidash,
    [SPECIES_SLOWPOKE] = gMonIcon_Slowpoke,
    [SPECIES_SLOWBRO] = gMonIcon_Slowbro,
    [SPECIES_MAGNEMITE] = gMonIcon_Magnemite,
    [SPECIES_MAGNETON] = gMonIcon_Magneton,
    [SPECIES_FARFETCHD] = gMonIcon_Farfetchd,
    [SPECIES_DODUO] = gMonIcon_Doduo,
    [SPECIES_DODRIO] = gMonIcon_Dodrio,
    [SPECIES_SEEL] = gMonIcon_Seel,
    [SPECIES_DEWGONG] = gMonIcon_Dewgong,
    [SPECIES_GRIMER] = gMonIcon_Grimer,
    [SPECIES_MUK] = gMonIcon_Muk,
    [SPECIES_SHELLDER] = gMonIcon_Shellder,
    [SPECIES_CLOYSTER] = gMonIcon_Cloyster,
    [SPECIES_GASTLY] = gMonIcon_Gastly,
    [SPECIES_HAUNTER] = gMonIcon_Haunter,
    [SPECIES_GENGAR] = gMonIcon_Gengar,
    [SPECIES_ONIX] = gMonIcon_Onix,
    [SPECIES_DROWZEE] = gMonIcon_Drowzee,
    [SPECIES_HYPNO] = gMonIcon_Hypno,
    [SPECIES_KRABBY] = gMonIcon_Krabby,
    [SPECIES_KINGLER] = gMonIcon_Kingler,
    [SPECIES_VOLTORB] = gMonIcon_Voltorb,
    [SPECIES_ELECTRODE] = gMonIcon_Electrode,
    [SPECIES_EXEGGCUTE] = gMonIcon_Exeggcute,
    [SPECIES_EXEGGUTOR] = gMonIcon_Exeggutor,
    [SPECIES_CUBONE] = gMonIcon_Cubone,
    [SPECIES_MAROWAK] = gMonIcon_Marowak,
    [SPECIES_HITMONLEE] = gMonIcon_Hitmonlee,
    [SPECIES_HITMONCHAN] = gMonIcon_Hitmonchan,
    [SPECIES_LICKITUNG] = gMonIcon_Lickitung,
    [SPECIES_KOFFING] = gMonIcon_Koffing,
    [SPECIES_WEEZING] = gMonIcon_Weezing,
    [SPECIES_RHYHORN] = gMonIcon_Rhyhorn,
    [SPECIES_RHYDON] = gMonIcon_Rhydon,
    [SPECIES_CHANSEY] = gMonIcon_Chansey,
    [SPECIES_TANGELA] = gMonIcon_Tangela,
    [SPECIES_KANGASKHAN] = gMonIcon_Kangaskhan,
    [SPECIES_HORSEA] = gMonIcon_Horsea,
    [SPECIES_SEADRA] = gMonIcon_Seadra,
    [SPECIES_GOLDEEN] = gMonIcon_Goldeen,
    [SPECIES_SEAKING] = gMonIcon_Seaking,
    [SPECIES_STARYU] = gMonIcon_Staryu,
    [SPECIES_STARMIE] = gMonIcon_Starmie,
    [SPECIES_MR_MIME] = gMonIcon_MrMime,
    [SPECIES_SCYTHER] = gMonIcon_Scyther,
    [SPECIES_JYNX] = gMonIcon_Jynx,
    [SPECIES_ELECTABUZZ] = gMonIcon_Electabuzz,
    [SPECIES_MAGMAR] = gMonIcon_Magmar,
    [SPECIES_PINSIR] = gMonIcon_Pinsir,
    [SPECIES_TAUROS] = gMonIcon_Tauros,
    [SPECIES_MAGIKARP] = gMonIcon_Magikarp,
    [SPECIES_GYARADOS] = gMonIcon_Gyarados,
    [SPECIES_LAPRAS] = gMonIcon_Lapras,
    [SPECIES_DITTO] = gMonIcon_Ditto,
    [SPECIES_EEVEE] = gMonIcon_Eevee,
    [SPECIES_VAPOREON] = gMonIcon_Vaporeon,
    [SPECIES_JOLTEON] = gMonIcon_Jolteon,
    [SPECIES_FLAREON] = gMonIcon_Flareon,
    [SPECIES_PORYGON] = gMonIcon_Porygon,
    [SPECIES_OMANYTE] = gMonIcon_Omanyte,
    [SPECIES_OMASTAR] = gMonIcon_Omastar,
    [SPECIES_KABUTO] = gMonIcon_Kabuto,
    [SPECIES_KABUTOPS] = gMonIcon_Kabutops,
    [SPECIES_AERODACTYL] = gMonIcon_Aerodactyl,
    [SPECIES_SNORLAX] = gMonIcon_Snorlax,
    [SPECIES_ARTICUNO] = gMonIcon_Articuno,
    [SPECIES_ZAPDOS] = gMonIcon_Zapdos,
    [SPECIES_MOLTRES] = gMonIcon_Moltres,
    [SPECIES_DRATINI] = gMonIcon_Dratini,
    [SPECIES_DRAGONAIR] = gMonIcon_Dragonair,
    [SPECIES_DRAGONITE] = gMonIcon_Dragonite,
    [SPECIES_MEWTWO] = gMonIcon_Mewtwo,
    [SPECIES_MEW] = gMonIcon_Mew,
    [SPECIES_CHIKORITA] = gMonIcon_Chikorita,
    [SPECIES_BAYLEEF] = gMonIcon_Bayleef,
    [SPECIES_MEGANIUM] = gMonIcon_Meganium,
    [SPECIES_CYNDAQUIL] = gMonIcon_Cyndaquil,
    [SPECIES_QUILAVA] = gMonIcon_Quilava,
    [SPECIES_TYPHLOSION] = gMonIcon_Typhlosion,
    [SPECIES_TOTODILE] = gMonIcon_Totodile,
    [SPECIES_CROCONAW] = gMonIcon_Croconaw,
    [SPECIES_FERALIGATR] = gMonIcon_Feraligatr,
    [SPECIES_SENTRET] = gMonIcon_Sentret,
    [SPECIES_FURRET] = gMonIcon_Furret,
    [SPECIES_HOOTHOOT] = gMonIcon_Hoothoot,
    [SPECIES_NOCTOWL] = gMonIcon_Noctowl,
    [SPECIES_LEDYBA] = gMonIcon_Ledyba,
    [SPECIES_LEDIAN] = gMonIcon_Ledian,
    [SPECIES_SPINARAK] = gMonIcon_Spinarak,
    [SPECIES_ARIADOS] = gMonIcon_Ariados,
    [SPECIES_CROBAT] = gMonIcon_Crobat,
    [SPECIES_CHINCHOU] = gMonIcon_Chinchou,
    [SPECIES_LANTURN] = gMonIcon_Lanturn,
    [SPECIES_PICHU] = gMonIcon_Pichu,
    [SPECIES_CLEFFA] = gMonIcon_Cleffa,
    [SPECIES_IGGLYBUFF] = gMonIcon_Igglybuff,
    [SPECIES_TOGEPI] = gMonIcon_Togepi,
    [SPECIES_TOGETIC] = gMonIcon_Togetic,
    [SPECIES_NATU] = gMonIcon_Natu,
    [SPECIES_XATU] = gMonIcon_Xatu,
    [SPECIES_MAREEP] = gMonIcon_Mareep,
    [SPECIES_FLAAFFY] = gMonIcon_Flaaffy,
    [SPECIES_AMPHAROS] = gMonIcon_Ampharos,
    [SPECIES_BELLOSSOM] = gMonIcon_Bellossom,
    [SPECIES_MARILL] = gMonIcon_Marill,
    [SPECIES_AZUMARILL] = gMonIcon_Azumarill,
    [SPECIES_SUDOWOODO] = gMonIcon_Sudowoodo,
    [SPECIES_POLITOED] = gMonIcon_Politoed,
    [SPECIES_HOPPIP] = gMonIcon_Hoppip,
    [SPECIES_SKIPLOOM] = gMonIcon_Skiploom,
    [SPECIES_JUMPLUFF] = gMonIcon_Jumpluff,
    [SPECIES_AIPOM] = gMonIcon_Aipom,
    [SPECIES_SUNKERN] = gMonIcon_Sunkern,
    [SPECIES_SUNFLORA] = gMonIcon_Sunflora,
    [SPECIES_YANMA] = gMonIcon_Yanma,
    [SPECIES_WOOPER] = gMonIcon_Wooper,
    [SPECIES_QUAGSIRE] = gMonIcon_Quagsire,
    [SPECIES_ESPEON] = gMonIcon_Espeon,
    [SPECIES_UMBREON] = gMonIcon_Umbreon,
    [SPECIES_MURKROW] = gMonIcon_Murkrow,
    [SPECIES_SLOWKING] = gMonIcon_Slowking,
    [SPECIES_MISDREAVUS] = gMonIcon_Misdreavus,
    [SPECIES_UNOWN] = gMonIcon_UnownA,
    [SPECIES_WOBBUFFET] = gMonIcon_Wobbuffet,
    [SPECIES_GIRAFARIG] = gMonIcon_Girafarig,
    [SPECIES_PINECO] = gMonIcon_Pineco,
    [SPECIES_FORRETRESS] = gMonIcon_Forretress,
    [SPECIES_DUNSPARCE] = gMonIcon_Dunsparce,
    [SPECIES_GLIGAR] = gMonIcon_Gligar,
    [SPECIES_STEELIX] = gMonIcon_Steelix,
    [SPECIES_SNUBBULL] = gMonIcon_Snubbull,
    [SPECIES_GRANBULL] = gMonIcon_Granbull,
    [SPECIES_QWILFISH] = gMonIcon_Qwilfish,
    [SPECIES_SCIZOR] = gMonIcon_Scizor,
    [SPECIES_SHUCKLE] = gMonIcon_Shuckle,
    [SPECIES_HERACROSS] = gMonIcon_Heracross,
    [SPECIES_SNEASEL] = gMonIcon_Sneasel,
    [SPECIES_TEDDIURSA] = gMonIcon_Teddiursa,
    [SPECIES_URSARING] = gMonIcon_Ursaring,
    [SPECIES_SLUGMA] = gMonIcon_Slugma,
    [SPECIES_MAGCARGO] = gMonIcon_Magcargo,
    [SPECIES_SWINUB] = gMonIcon_Swinub,
    [SPECIES_PILOSWINE] = gMonIcon_Piloswine,
    [SPECIES_CORSOLA] = gMonIcon_Corsola,
    [SPECIES_REMORAID] = gMonIcon_Remoraid,
    [SPECIES_OCTILLERY] = gMonIcon_Octillery,
    [SPECIES_DELIBIRD] = gMonIcon_Delibird,
    [SPECIES_MANTINE] = gMonIcon_Mantine,
    [SPECIES_SKARMORY] = gMonIcon_Skarmory,
    [SPECIES_HOUNDOUR] = gMonIcon_Houndour,
    [SPECIES_HOUNDOOM] = gMonIcon_Houndoom,
    [SPECIES_KINGDRA] = gMonIcon_Kingdra,
    [SPECIES_PHANPY] = gMonIcon_Phanpy,
    [SPECIES_DONPHAN] = gMonIcon_Donphan,
    [SPECIES_PORYGON2] = gMonIcon_Porygon2,
    [SPECIES_STANTLER] = gMonIcon_Stantler,
    [SPECIES_SMEARGLE] = gMonIcon_Smeargle,
    [SPECIES_TYROGUE] = gMonIcon_Tyrogue,
    [SPECIES_HITMONTOP] = gMonIcon_Hitmontop,
    [SPECIES_SMOOCHUM] = gMonIcon_Smoochum,
    [SPECIES_ELEKID] = gMonIcon_Elekid,
    [SPECIES_MAGBY] = gMonIcon_Magby,
    [SPECIES_MILTANK] = gMonIcon_Miltank,
    [SPECIES_BLISSEY] = gMonIcon_Blissey,
    [SPECIES_RAIKOU] = gMonIcon_Raikou,
    [SPECIES_ENTEI] = gMonIcon_Entei,
    [SPECIES_SUICUNE] = gMonIcon_Suicune,
    [SPECIES_LARVITAR] = gMonIcon_Larvitar,
    [SPECIES_PUPITAR] = gMonIcon_Pupitar,
    [SPECIES_TYRANITAR] = gMonIcon_Tyranitar,
    [SPECIES_LUGIA] = gMonIcon_Lugia,
    [SPECIES_HO_OH] = gMonIcon_HoOh,
    [SPECIES_CELEBI] = gMonIcon_Celebi,
    [SPECIES_OLD_UNOWN_B] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_C] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_D] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_E] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_F] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_G] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_H] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_I] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_J] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_K] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_L] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_M] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_N] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_O] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_P] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_Q] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_R] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_S] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_T] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_U] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_V] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_W] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_X] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_Y] = gMonIcon_QuestionMark,
    [SPECIES_OLD_UNOWN_Z] = gMonIcon_QuestionMark,
    [SPECIES_TREECKO] = gMonIcon_Treecko,
    [SPECIES_GROVYLE] = gMonIcon_Grovyle,
    [SPECIES_SCEPTILE] = gMonIcon_Sceptile,
    [SPECIES_TORCHIC] = gMonIcon_Torchic,
    [SPECIES_COMBUSKEN] = gMonIcon_Combusken,
    [SPECIES_BLAZIKEN] = gMonIcon_Blaziken,
    [SPECIES_MUDKIP] = gMonIcon_Mudkip,
    [SPECIES_MARSHTOMP] = gMonIcon_Marshtomp,
    [SPECIES_SWAMPERT] = gMonIcon_Swampert,
    [SPECIES_POOCHYENA] = gMonIcon_Poochyena,
    [SPECIES_MIGHTYENA] = gMonIcon_Mightyena,
    [SPECIES_ZIGZAGOON] = gMonIcon_Zigzagoon,
    [SPECIES_LINOONE] = gMonIcon_Linoone,
    [SPECIES_WURMPLE] = gMonIcon_Wurmple,
    [SPECIES_SILCOON] = gMonIcon_Silcoon,
    [SPECIES_BEAUTIFLY] = gMonIcon_Beautifly,
    [SPECIES_CASCOON] = gMonIcon_Cascoon,
    [SPECIES_DUSTOX] = gMonIcon_Dustox,
    [SPECIES_LOTAD] = gMonIcon_Lotad,
    [SPECIES_LOMBRE] = gMonIcon_Lombre,
    [SPECIES_LUDICOLO] = gMonIcon_Ludicolo,
    [SPECIES_SEEDOT] = gMonIcon_Seedot,
    [SPECIES_NUZLEAF] = gMonIcon_Nuzleaf,
    [SPECIES_SHIFTRY] = gMonIcon_Shiftry,
    [SPECIES_NINCADA] = gMonIcon_Nincada,
    [SPECIES_NINJASK] = gMonIcon_Ninjask,
    [SPECIES_SHEDINJA] = gMonIcon_Shedinja,
    [SPECIES_TAILLOW] = gMonIcon_Taillow,
    [SPECIES_SWELLOW] = gMonIcon_Swellow,
    [SPECIES_SHROOMISH] = gMonIcon_Shroomish,
    [SPECIES_BRELOOM] = gMonIcon_Breloom,
    [SPECIES_SPINDA] = gMonIcon_Spinda,
    [SPECIES_WINGULL] = gMonIcon_Wingull,
    [SPECIES_PELIPPER] = gMonIcon_Pelipper,
    [SPECIES_SURSKIT] = gMonIcon_Surskit,
    [SPECIES_MASQUERAIN] = gMonIcon_Masquerain,
    [SPECIES_WAILMER] = gMonIcon_Wailmer,
    [SPECIES_WAILORD] = gMonIcon_Wailord,
    [SPECIES_SKITTY] = gMonIcon_Skitty,
    [SPECIES_DELCATTY] = gMonIcon_Delcatty,
    [SPECIES_KECLEON] = gMonIcon_Kecleon,
    [SPECIES_BALTOY] = gMonIcon_Baltoy,
    [SPECIES_CLAYDOL] = gMonIcon_Claydol,
    [SPECIES_NOSEPASS] = gMonIcon_Nosepass,
    [SPECIES_TORKOAL] = gMonIcon_Torkoal,
    [SPECIES_SABLEYE] = gMonIcon_Sableye,
    [SPECIES_BARBOACH] = gMonIcon_Barboach,
    [SPECIES_WHISCASH] = gMonIcon_Whiscash,
    [SPECIES_LUVDISC] = gMonIcon_Luvdisc,
    [SPECIES_CORPHISH] = gMonIcon_Corphish,
    [SPECIES_CRAWDAUNT] = gMonIcon_Crawdaunt,
    [SPECIES_FEEBAS] = gMonIcon_Feebas,
    [SPECIES_MILOTIC] = gMonIcon_Milotic,
    [SPECIES_CARVANHA] = gMonIcon_Carvanha,
    [SPECIES_SHARPEDO] = gMonIcon_Sharpedo,
    [SPECIES_TRAPINCH] = gMonIcon_Trapinch,
    [SPECIES_VIBRAVA] = gMonIcon_Vibrava,
    [SPECIES_FLYGON] = gMonIcon_Flygon,
    [SPECIES_MAKUHITA] = gMonIcon_Makuhita,
    [SPECIES_HARIYAMA] = gMonIcon_Hariyama,
    [SPECIES_ELECTRIKE] = gMonIcon_Electrike,
    [SPECIES_MANECTRIC] = gMonIcon_Manectric,
    [SPECIES_NUMEL] = gMonIcon_Numel,
    [SPECIES_CAMERUPT] = gMonIcon_Camerupt,
    [SPECIES_SPHEAL] = gMonIcon_Spheal,
    [SPECIES_SEALEO] = gMonIcon_Sealeo,
    [SPECIES_WALREIN] = gMonIcon_Walrein,
    [SPECIES_CACNEA] = gMonIcon_Cacnea,
    [SPECIES_CACTURNE] = gMonIcon_Cacturne,
    [SPECIES_SNORUNT] = gMonIcon_Snorunt,
    [SPECIES_GLALIE] = gMonIcon_Glalie,
    [SPECIES_LUNATONE] = gMonIcon_Lunatone,
    [SPECIES_SOLROCK] = gMonIcon_Solrock,
    [SPECIES_AZURILL] = gMonIcon_Azurill,
    [SPECIES_SPOINK] = gMonIcon_Spoink,
    [SPECIES_GRUMPIG] = gMonIcon_Grumpig,
    [SPECIES_PLUSLE] = gMonIcon_Plusle,
    [SPECIES_MINUN] = gMonIcon_Minun,
    [SPECIES_MAWILE] = gMonIcon_Mawile,
    [SPECIES_MEDITITE] = gMonIcon_Meditite,
    [SPECIES_MEDICHAM] = gMonIcon_Medicham,
    [SPECIES_SWABLU] = gMonIcon_Swablu,
    [SPECIES_ALTARIA] = gMonIcon_Altaria,
    [SPECIES_WYNAUT] = gMonIcon_Wynaut,
    [SPECIES_DUSKULL] = gMonIcon_Duskull,
    [SPECIES_DUSCLOPS] = gMonIcon_Dusclops,
    [SPECIES_ROSELIA] = gMonIcon_Roselia,
    [SPECIES_SLAKOTH] = gMonIcon_Slakoth,
    [SPECIES_VIGOROTH] = gMonIcon_Vigoroth,
    [SPECIES_SLAKING] = gMonIcon_Slaking,
    [SPECIES_GULPIN] = gMonIcon_Gulpin,
    [SPECIES_SWALOT] = gMonIcon_Swalot,
    [SPECIES_TROPIUS] = gMonIcon_Tropius,
    [SPECIES_WHISMUR] = gMonIcon_Whismur,
    [SPECIES_LOUDRED] = gMonIcon_Loudred,
    [SPECIES_EXPLOUD] = gMonIcon_Exploud,
    [SPECIES_CLAMPERL] = gMonIcon_Clamperl,
    [SPECIES_HUNTAIL] = gMonIcon_Huntail,
    [SPECIES_GOREBYSS] = gMonIcon_Gorebyss,
    [SPECIES_ABSOL] = gMonIcon_Absol,
    [SPECIES_SHUPPET] = gMonIcon_Shuppet,
    [SPECIES_BANETTE] = gMonIcon_Banette,
    [SPECIES_SEVIPER] = gMonIcon_Seviper,
    [SPECIES_ZANGOOSE] = gMonIcon_Zangoose,
    [SPECIES_RELICANTH] = gMonIcon_Relicanth,
    [SPECIES_ARON] = gMonIcon_Aron,
    [SPECIES_LAIRON] = gMonIcon_Lairon,
    [SPECIES_AGGRON] = gMonIcon_Aggron,
    [SPECIES_CASTFORM] = gMonIcon_Castform,
    [SPECIES_VOLBEAT] = gMonIcon_Volbeat,
    [SPECIES_ILLUMISE] = gMonIcon_Illumise,
    [SPECIES_LILEEP] = gMonIcon_Lileep,
    [SPECIES_CRADILY] = gMonIcon_Cradily,
    [SPECIES_ANORITH] = gMonIcon_Anorith,
    [SPECIES_ARMALDO] = gMonIcon_Armaldo,
    [SPECIES_RALTS] = gMonIcon_Ralts,
    [SPECIES_KIRLIA] = gMonIcon_Kirlia,
    [SPECIES_GARDEVOIR] = gMonIcon_Gardevoir,
    [SPECIES_BAGON] = gMonIcon_Bagon,
    [SPECIES_SHELGON] = gMonIcon_Shelgon,
    [SPECIES_SALAMENCE] = gMonIcon_Salamence,
    [SPECIES_BELDUM] = gMonIcon_Beldum,
    [SPECIES_METANG] = gMonIcon_Metang,
    [SPECIES_METAGROSS] = gMonIcon_Metagross,
    [SPECIES_REGIROCK] = gMonIcon_Regirock,
    [SPECIES_REGICE] = gMonIcon_Regice,
    [SPECIES_REGISTEEL] = gMonIcon_Registeel,
    [SPECIES_KYOGRE] = gMonIcon_Kyogre,
    [SPECIES_GROUDON] = gMonIcon_Groudon,
    [SPECIES_RAYQUAZA] = gMonIcon_Rayquaza,
    [SPECIES_LATIAS] = gMonIcon_Latias,
    [SPECIES_LATIOS] = gMonIcon_Latios,
    [SPECIES_JIRACHI] = gMonIcon_Jirachi,
    [SPECIES_DEOXYS] = gMonIcon_Deoxys,
    [SPECIES_CHIMECHO] = gMonIcon_Chimecho,
    [SPECIES_EGG] = gMonIcon_Egg,
    [SPECIES_UNOWN_B] = gMonIcon_UnownB,
    [SPECIES_UNOWN_C] = gMonIcon_UnownC,
    [SPECIES_UNOWN_D] = gMonIcon_UnownD,
    [SPECIES_UNOWN_E] = gMonIcon_UnownE,
    [SPECIES_UNOWN_F] = gMonIcon_UnownF,
    [SPECIES_UNOWN_G] = gMonIcon_UnownG,
    [SPECIES_UNOWN_H] = gMonIcon_UnownH,
    [SPECIES_UNOWN_I] = gMonIcon_UnownI,
    [SPECIES_UNOWN_J] = gMonIcon_UnownJ,
    [SPECIES_UNOWN_K] = gMonIcon_UnownK,
    [SPECIES_UNOWN_L] = gMonIcon_UnownL,
    [SPECIES_UNOWN_M] = gMonIcon_UnownM,
    [SPECIES_UNOWN_N] = gMonIcon_UnownN,
    [SPECIES_UNOWN_O] = gMonIcon_UnownO,
    [SPECIES_UNOWN_P] = gMonIcon_UnownP,
    [SPECIES_UNOWN_Q] = gMonIcon_UnownQ,
    [SPECIES_UNOWN_R] = gMonIcon_UnownR,
    [SPECIES_UNOWN_S] = gMonIcon_UnownS,
    [SPECIES_UNOWN_T] = gMonIcon_UnownT,
    [SPECIES_UNOWN_U] = gMonIcon_UnownU,
    [SPECIES_UNOWN_V] = gMonIcon_UnownV,
    [SPECIES_UNOWN_W] = gMonIcon_UnownW,
    [SPECIES_UNOWN_X] = gMonIcon_UnownX,
    [SPECIES_UNOWN_Y] = gMonIcon_UnownY,
    [SPECIES_UNOWN_Z] = gMonIcon_UnownZ,
    [SPECIES_UNOWN_EMARK] = gMonIcon_UnownExclamationMark,
    [SPECIES_UNOWN_QMARK] = gMonIcon_UnownQuestionMark,
};

const u8 *const gMonOldIconTable[] =
{
    [SPECIES_NONE] = gMonIcon_BulbasaurOld,
    [SPECIES_BULBASAUR] = gMonIcon_BulbasaurOld,
    [SPECIES_IVYSAUR] = gMonIcon_IvysaurOld,
    [SPECIES_VENUSAUR] = gMonIcon_VenusaurOld,
    [SPECIES_CHARMANDER] = gMonIcon_CharmanderOld,
    [SPECIES_CHARMELEON] = gMonIcon_CharmeleonOld,
    [SPECIES_CHARIZARD] = gMonIcon_CharizardOld,
    [SPECIES_SQUIRTLE] = gMonIcon_SquirtleOld,
    [SPECIES_WARTORTLE] = gMonIcon_WartortleOld,
    [SPECIES_BLASTOISE] = gMonIcon_BlastoiseOld,
    [SPECIES_CATERPIE] = gMonIcon_CaterpieOld,
    [SPECIES_METAPOD] = gMonIcon_MetapodOld,
    [SPECIES_BUTTERFREE] = gMonIcon_ButterfreeOld,
    [SPECIES_WEEDLE] = gMonIcon_WeedleOld,
    [SPECIES_KAKUNA] = gMonIcon_KakunaOld,
    [SPECIES_BEEDRILL] = gMonIcon_BeedrillOld,
    [SPECIES_PIDGEY] = gMonIcon_PidgeyOld,
    [SPECIES_PIDGEOTTO] = gMonIcon_PidgeottoOld,
    [SPECIES_PIDGEOT] = gMonIcon_PidgeotOld,
    [SPECIES_RATTATA] = gMonIcon_RattataOld,
    [SPECIES_RATICATE] = gMonIcon_RaticateOld,
    [SPECIES_SPEAROW] = gMonIcon_SpearowOld,
    [SPECIES_FEAROW] = gMonIcon_FearowOld,
    [SPECIES_EKANS] = gMonIcon_EkansOld,
    [SPECIES_ARBOK] = gMonIcon_ArbokOld,
    [SPECIES_PIKACHU] = gMonIcon_PikachuOld,
    [SPECIES_RAICHU] = gMonIcon_RaichuOld,
    [SPECIES_SANDSHREW] = gMonIcon_SandshrewOld,
    [SPECIES_SANDSLASH] = gMonIcon_SandslashOld,
    [SPECIES_NIDORAN_F] = gMonIcon_NidoranFOld,
    [SPECIES_NIDORINA] = gMonIcon_NidorinaOld,
    [SPECIES_NIDOQUEEN] = gMonIcon_NidoqueenOld,
    [SPECIES_NIDORAN_M] = gMonIcon_NidoranMOld,
    [SPECIES_NIDORINO] = gMonIcon_NidorinoOld,
    [SPECIES_NIDOKING] = gMonIcon_NidokingOld,
    [SPECIES_CLEFAIRY] = gMonIcon_ClefairyOld,
    [SPECIES_CLEFABLE] = gMonIcon_ClefableOld,
    [SPECIES_VULPIX] = gMonIcon_VulpixOld,
    [SPECIES_NINETALES] = gMonIcon_NinetalesOld,
    [SPECIES_JIGGLYPUFF] = gMonIcon_JigglypuffOld,
    [SPECIES_WIGGLYTUFF] = gMonIcon_WigglytuffOld,
    [SPECIES_ZUBAT] = gMonIcon_ZubatOld,
    [SPECIES_GOLBAT] = gMonIcon_GolbatOld,
    [SPECIES_ODDISH] = gMonIcon_OddishOld,
    [SPECIES_GLOOM] = gMonIcon_GloomOld,
    [SPECIES_VILEPLUME] = gMonIcon_VileplumeOld,
    [SPECIES_PARAS] = gMonIcon_ParasOld,
    [SPECIES_PARASECT] = gMonIcon_ParasectOld,
    [SPECIES_VENONAT] = gMonIcon_VenonatOld,
    [SPECIES_VENOMOTH] = gMonIcon_VenomothOld,
    [SPECIES_DIGLETT] = gMonIcon_DiglettOld,
    [SPECIES_DUGTRIO] = gMonIcon_DugtrioOld,
    [SPECIES_MEOWTH] = gMonIcon_MeowthOld,
    [SPECIES_PERSIAN] = gMonIcon_PersianOld,
    [SPECIES_PSYDUCK] = gMonIcon_PsyduckOld,
    [SPECIES_GOLDUCK] = gMonIcon_GolduckOld,
    [SPECIES_MANKEY] = gMonIcon_MankeyOld,
    [SPECIES_PRIMEAPE] = gMonIcon_PrimeapeOld,
    [SPECIES_GROWLITHE] = gMonIcon_GrowlitheOld,
    [SPECIES_ARCANINE] = gMonIcon_ArcanineOld,
    [SPECIES_POLIWAG] = gMonIcon_PoliwagOld,
    [SPECIES_POLIWHIRL] = gMonIcon_PoliwhirlOld,
    [SPECIES_POLIWRATH] = gMonIcon_PoliwrathOld,
    [SPECIES_ABRA] = gMonIcon_AbraOld,
    [SPECIES_KADABRA] = gMonIcon_KadabraOld,
    [SPECIES_ALAKAZAM] = gMonIcon_AlakazamOld,
    [SPECIES_MACHOP] = gMonIcon_MachopOld,
    [SPECIES_MACHOKE] = gMonIcon_MachokeOld,
    [SPECIES_MACHAMP] = gMonIcon_MachampOld,
    [SPECIES_BELLSPROUT] = gMonIcon_BellsproutOld,
    [SPECIES_WEEPINBELL] = gMonIcon_WeepinbellOld,
    [SPECIES_VICTREEBEL] = gMonIcon_VictreebelOld,
    [SPECIES_TENTACOOL] = gMonIcon_TentacoolOld,
    [SPECIES_TENTACRUEL] = gMonIcon_TentacruelOld,
    [SPECIES_GEODUDE] = gMonIcon_GeodudeOld,
    [SPECIES_GRAVELER] = gMonIcon_GravelerOld,
    [SPECIES_GOLEM] = gMonIcon_GolemOld,
    [SPECIES_PONYTA] = gMonIcon_PonytaOld,
    [SPECIES_RAPIDASH] = gMonIcon_RapidashOld,
    [SPECIES_SLOWPOKE] = gMonIcon_SlowpokeOld,
    [SPECIES_SLOWBRO] = gMonIcon_SlowbroOld,
    [SPECIES_MAGNEMITE] = gMonIcon_MagnemiteOld,
    [SPECIES_MAGNETON] = gMonIcon_MagnetonOld,
    [SPECIES_FARFETCHD] = gMonIcon_FarfetchdOld,
    [SPECIES_DODUO] = gMonIcon_DoduoOld,
    [SPECIES_DODRIO] = gMonIcon_DodrioOld,
    [SPECIES_SEEL] = gMonIcon_SeelOld,
    [SPECIES_DEWGONG] = gMonIcon_DewgongOld,
    [SPECIES_GRIMER] = gMonIcon_GrimerOld,
    [SPECIES_MUK] = gMonIcon_MukOld,
    [SPECIES_SHELLDER] = gMonIcon_ShellderOld,
    [SPECIES_CLOYSTER] = gMonIcon_CloysterOld,
    [SPECIES_GASTLY] = gMonIcon_GastlyOld,
    [SPECIES_HAUNTER] = gMonIcon_HaunterOld,
    [SPECIES_GENGAR] = gMonIcon_GengarOld,
    [SPECIES_ONIX] = gMonIcon_OnixOld,
    [SPECIES_DROWZEE] = gMonIcon_DrowzeeOld,
    [SPECIES_HYPNO] = gMonIcon_HypnoOld,
    [SPECIES_KRABBY] = gMonIcon_KrabbyOld,
    [SPECIES_KINGLER] = gMonIcon_KinglerOld,
    [SPECIES_VOLTORB] = gMonIcon_VoltorbOld,
    [SPECIES_ELECTRODE] = gMonIcon_ElectrodeOld,
    [SPECIES_EXEGGCUTE] = gMonIcon_ExeggcuteOld,
    [SPECIES_EXEGGUTOR] = gMonIcon_ExeggutorOld,
    [SPECIES_CUBONE] = gMonIcon_CuboneOld,
    [SPECIES_MAROWAK] = gMonIcon_MarowakOld,
    [SPECIES_HITMONLEE] = gMonIcon_HitmonleeOld,
    [SPECIES_HITMONCHAN] = gMonIcon_HitmonchanOld,
    [SPECIES_LICKITUNG] = gMonIcon_LickitungOld,
    [SPECIES_KOFFING] = gMonIcon_KoffingOld,
    [SPECIES_WEEZING] = gMonIcon_WeezingOld,
    [SPECIES_RHYHORN] = gMonIcon_RhyhornOld,
    [SPECIES_RHYDON] = gMonIcon_RhydonOld,
    [SPECIES_CHANSEY] = gMonIcon_ChanseyOld,
    [SPECIES_TANGELA] = gMonIcon_TangelaOld,
    [SPECIES_KANGASKHAN] = gMonIcon_KangaskhanOld,
    [SPECIES_HORSEA] = gMonIcon_HorseaOld,
    [SPECIES_SEADRA] = gMonIcon_SeadraOld,
    [SPECIES_GOLDEEN] = gMonIcon_GoldeenOld,
    [SPECIES_SEAKING] = gMonIcon_SeakingOld,
    [SPECIES_STARYU] = gMonIcon_StaryuOld,
    [SPECIES_STARMIE] = gMonIcon_StarmieOld,
    [SPECIES_MR_MIME] = gMonIcon_MrMimeOld,
    [SPECIES_SCYTHER] = gMonIcon_ScytherOld,
    [SPECIES_JYNX] = gMonIcon_JynxOld,
    [SPECIES_ELECTABUZZ] = gMonIcon_ElectabuzzOld,
    [SPECIES_MAGMAR] = gMonIcon_MagmarOld,
    [SPECIES_PINSIR] = gMonIcon_PinsirOld,
    [SPECIES_TAUROS] = gMonIcon_TaurosOld,
    [SPECIES_MAGIKARP] = gMonIcon_MagikarpOld,
    [SPECIES_GYARADOS] = gMonIcon_GyaradosOld,
    [SPECIES_LAPRAS] = gMonIcon_LaprasOld,
    [SPECIES_DITTO] = gMonIcon_DittoOld,
    [SPECIES_EEVEE] = gMonIcon_EeveeOld,
    [SPECIES_VAPOREON] = gMonIcon_VaporeonOld,
    [SPECIES_JOLTEON] = gMonIcon_JolteonOld,
    [SPECIES_FLAREON] = gMonIcon_FlareonOld,
    [SPECIES_PORYGON] = gMonIcon_PorygonOld,
    [SPECIES_OMANYTE] = gMonIcon_OmanyteOld,
    [SPECIES_OMASTAR] = gMonIcon_OmastarOld,
    [SPECIES_KABUTO] = gMonIcon_KabutoOld,
    [SPECIES_KABUTOPS] = gMonIcon_KabutopsOld,
    [SPECIES_AERODACTYL] = gMonIcon_AerodactylOld,
    [SPECIES_SNORLAX] = gMonIcon_SnorlaxOld,
    [SPECIES_ARTICUNO] = gMonIcon_ArticunoOld,
    [SPECIES_ZAPDOS] = gMonIcon_ZapdosOld,
    [SPECIES_MOLTRES] = gMonIcon_MoltresOld,
    [SPECIES_DRATINI] = gMonIcon_DratiniOld,
    [SPECIES_DRAGONAIR] = gMonIcon_DragonairOld,
    [SPECIES_DRAGONITE] = gMonIcon_DragoniteOld,
    [SPECIES_MEWTWO] = gMonIcon_MewtwoOld,
    [SPECIES_MEW] = gMonIcon_MewOld,
    [SPECIES_CHIKORITA] = gMonIcon_ChikoritaOld,
    [SPECIES_BAYLEEF] = gMonIcon_BayleefOld,
    [SPECIES_MEGANIUM] = gMonIcon_MeganiumOld,
    [SPECIES_CYNDAQUIL] = gMonIcon_CyndaquilOld,
    [SPECIES_QUILAVA] = gMonIcon_QuilavaOld,
    [SPECIES_TYPHLOSION] = gMonIcon_TyphlosionOld,
    [SPECIES_TOTODILE] = gMonIcon_TotodileOld,
    [SPECIES_CROCONAW] = gMonIcon_CroconawOld,
    [SPECIES_FERALIGATR] = gMonIcon_FeraligatrOld,
    [SPECIES_SENTRET] = gMonIcon_SentretOld,
    [SPECIES_FURRET] = gMonIcon_FurretOld,
    [SPECIES_HOOTHOOT] = gMonIcon_HoothootOld,
    [SPECIES_NOCTOWL] = gMonIcon_NoctowlOld,
    [SPECIES_LEDYBA] = gMonIcon_LedybaOld,
    [SPECIES_LEDIAN] = gMonIcon_LedianOld,
    [SPECIES_SPINARAK] = gMonIcon_SpinarakOld,
    [SPECIES_ARIADOS] = gMonIcon_AriadosOld,
    [SPECIES_CROBAT] = gMonIcon_CrobatOld,
    [SPECIES_CHINCHOU] = gMonIcon_ChinchouOld,
    [SPECIES_LANTURN] = gMonIcon_LanturnOld,
    [SPECIES_PICHU] = gMonIcon_PichuOld,
    [SPECIES_CLEFFA] = gMonIcon_CleffaOld,
    [SPECIES_IGGLYBUFF] = gMonIcon_IgglybuffOld,
    [SPECIES_TOGEPI] = gMonIcon_TogepiOld,
    [SPECIES_TOGETIC] = gMonIcon_TogeticOld,
    [SPECIES_NATU] = gMonIcon_NatuOld,
    [SPECIES_XATU] = gMonIcon_XatuOld,
    [SPECIES_MAREEP] = gMonIcon_MareepOld,
    [SPECIES_FLAAFFY] = gMonIcon_FlaaffyOld,
    [SPECIES_AMPHAROS] = gMonIcon_AmpharosOld,
    [SPECIES_BELLOSSOM] = gMonIcon_BellossomOld,
    [SPECIES_MARILL] = gMonIcon_MarillOld,
    [SPECIES_AZUMARILL] = gMonIcon_AzumarillOld,
    [SPECIES_SUDOWOODO] = gMonIcon_SudowoodoOld,
    [SPECIES_POLITOED] = gMonIcon_PolitoedOld,
    [SPECIES_HOPPIP] = gMonIcon_HoppipOld,
    [SPECIES_SKIPLOOM] = gMonIcon_SkiploomOld,
    [SPECIES_JUMPLUFF] = gMonIcon_JumpluffOld,
    [SPECIES_AIPOM] = gMonIcon_AipomOld,
    [SPECIES_SUNKERN] = gMonIcon_SunkernOld,
    [SPECIES_SUNFLORA] = gMonIcon_SunfloraOld,
    [SPECIES_YANMA] = gMonIcon_YanmaOld,
    [SPECIES_WOOPER] = gMonIcon_WooperOld,
    [SPECIES_QUAGSIRE] = gMonIcon_QuagsireOld,
    [SPECIES_ESPEON] = gMonIcon_EspeonOld,
    [SPECIES_UMBREON] = gMonIcon_UmbreonOld,
    [SPECIES_MURKROW] = gMonIcon_MurkrowOld,
    [SPECIES_SLOWKING] = gMonIcon_SlowkingOld,
    [SPECIES_MISDREAVUS] = gMonIcon_MisdreavusOld,
    [SPECIES_UNOWN] = gMonIcon_UnownAOld,
    [SPECIES_WOBBUFFET] = gMonIcon_WobbuffetOld,
    [SPECIES_GIRAFARIG] = gMonIcon_GirafarigOld,
    [SPECIES_PINECO] = gMonIcon_PinecoOld,
    [SPECIES_FORRETRESS] = gMonIcon_ForretressOld,
    [SPECIES_DUNSPARCE] = gMonIcon_DunsparceOld,
    [SPECIES_GLIGAR] = gMonIcon_GligarOld,
    [SPECIES_STEELIX] = gMonIcon_SteelixOld,
    [SPECIES_SNUBBULL] = gMonIcon_SnubbullOld,
    [SPECIES_GRANBULL] = gMonIcon_GranbullOld,
    [SPECIES_QWILFISH] = gMonIcon_QwilfishOld,
    [SPECIES_SCIZOR] = gMonIcon_ScizorOld,
    [SPECIES_SHUCKLE] = gMonIcon_ShuckleOld,
    [SPECIES_HERACROSS] = gMonIcon_HeracrossOld,
    [SPECIES_SNEASEL] = gMonIcon_SneaselOld,
    [SPECIES_TEDDIURSA] = gMonIcon_TeddiursaOld,
    [SPECIES_URSARING] = gMonIcon_UrsaringOld,
    [SPECIES_SLUGMA] = gMonIcon_SlugmaOld,
    [SPECIES_MAGCARGO] = gMonIcon_MagcargoOld,
    [SPECIES_SWINUB] = gMonIcon_SwinubOld,
    [SPECIES_PILOSWINE] = gMonIcon_PiloswineOld,
    [SPECIES_CORSOLA] = gMonIcon_CorsolaOld,
    [SPECIES_REMORAID] = gMonIcon_RemoraidOld,
    [SPECIES_OCTILLERY] = gMonIcon_OctilleryOld,
    [SPECIES_DELIBIRD] = gMonIcon_DelibirdOld,
    [SPECIES_MANTINE] = gMonIcon_MantineOld,
    [SPECIES_SKARMORY] = gMonIcon_SkarmoryOld,
    [SPECIES_HOUNDOUR] = gMonIcon_HoundourOld,
    [SPECIES_HOUNDOOM] = gMonIcon_HoundoomOld,
    [SPECIES_KINGDRA] = gMonIcon_KingdraOld,
    [SPECIES_PHANPY] = gMonIcon_PhanpyOld,
    [SPECIES_DONPHAN] = gMonIcon_DonphanOld,
    [SPECIES_PORYGON2] = gMonIcon_Porygon2Old,
    [SPECIES_STANTLER] = gMonIcon_StantlerOld,
    [SPECIES_SMEARGLE] = gMonIcon_SmeargleOld,
    [SPECIES_TYROGUE] = gMonIcon_TyrogueOld,
    [SPECIES_HITMONTOP] = gMonIcon_HitmontopOld,
    [SPECIES_SMOOCHUM] = gMonIcon_SmoochumOld,
    [SPECIES_ELEKID] = gMonIcon_ElekidOld,
    [SPECIES_MAGBY] = gMonIcon_MagbyOld,
    [SPECIES_MILTANK] = gMonIcon_MiltankOld,
    [SPECIES_BLISSEY] = gMonIcon_BlisseyOld,
    [SPECIES_RAIKOU] = gMonIcon_RaikouOld,
    [SPECIES_ENTEI] = gMonIcon_EnteiOld,
    [SPECIES_SUICUNE] = gMonIcon_SuicuneOld,
    [SPECIES_LARVITAR] = gMonIcon_LarvitarOld,
    [SPECIES_PUPITAR] = gMonIcon_PupitarOld,
    [SPECIES_TYRANITAR] = gMonIcon_TyranitarOld,
    [SPECIES_LUGIA] = gMonIcon_LugiaOld,
    [SPECIES_HO_OH] = gMonIcon_HoOhOld,
    [SPECIES_CELEBI] = gMonIcon_CelebiOld,
    [SPECIES_OLD_UNOWN_B] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_C] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_D] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_E] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_F] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_G] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_H] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_I] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_J] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_K] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_L] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_M] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_N] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_O] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_P] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_Q] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_R] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_S] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_T] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_U] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_V] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_W] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_X] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_Y] = gMonIcon_QuestionMarkOld,
    [SPECIES_OLD_UNOWN_Z] = gMonIcon_QuestionMarkOld,
    [SPECIES_TREECKO] = gMonIcon_TreeckoOld,
    [SPECIES_GROVYLE] = gMonIcon_GrovyleOld,
    [SPECIES_SCEPTILE] = gMonIcon_SceptileOld,
    [SPECIES_TORCHIC] = gMonIcon_TorchicOld,
    [SPECIES_COMBUSKEN] = gMonIcon_CombuskenOld,
    [SPECIES_BLAZIKEN] = gMonIcon_BlazikenOld,
    [SPECIES_MUDKIP] = gMonIcon_MudkipOld,
    [SPECIES_MARSHTOMP] = gMonIcon_MarshtompOld,
    [SPECIES_SWAMPERT] = gMonIcon_SwampertOld,
    [SPECIES_POOCHYENA] = gMonIcon_PoochyenaOld,
    [SPECIES_MIGHTYENA] = gMonIcon_MightyenaOld,
    [SPECIES_ZIGZAGOON] = gMonIcon_ZigzagoonOld,
    [SPECIES_LINOONE] = gMonIcon_LinooneOld,
    [SPECIES_WURMPLE] = gMonIcon_WurmpleOld,
    [SPECIES_SILCOON] = gMonIcon_SilcoonOld,
    [SPECIES_BEAUTIFLY] = gMonIcon_BeautiflyOld,
    [SPECIES_CASCOON] = gMonIcon_CascoonOld,
    [SPECIES_DUSTOX] = gMonIcon_DustoxOld,
    [SPECIES_LOTAD] = gMonIcon_LotadOld,
    [SPECIES_LOMBRE] = gMonIcon_LombreOld,
    [SPECIES_LUDICOLO] = gMonIcon_LudicoloOld,
    [SPECIES_SEEDOT] = gMonIcon_SeedotOld,
    [SPECIES_NUZLEAF] = gMonIcon_NuzleafOld,
    [SPECIES_SHIFTRY] = gMonIcon_ShiftryOld,
    [SPECIES_NINCADA] = gMonIcon_NincadaOld,
    [SPECIES_NINJASK] = gMonIcon_NinjaskOld,
    [SPECIES_SHEDINJA] = gMonIcon_ShedinjaOld,
    [SPECIES_TAILLOW] = gMonIcon_TaillowOld,
    [SPECIES_SWELLOW] = gMonIcon_SwellowOld,
    [SPECIES_SHROOMISH] = gMonIcon_ShroomishOld,
    [SPECIES_BRELOOM] = gMonIcon_BreloomOld,
    [SPECIES_SPINDA] = gMonIcon_SpindaOld,
    [SPECIES_WINGULL] = gMonIcon_WingullOld,
    [SPECIES_PELIPPER] = gMonIcon_PelipperOld,
    [SPECIES_SURSKIT] = gMonIcon_SurskitOld,
    [SPECIES_MASQUERAIN] = gMonIcon_MasquerainOld,
    [SPECIES_WAILMER] = gMonIcon_WailmerOld,
    [SPECIES_WAILORD] = gMonIcon_WailordOld,
    [SPECIES_SKITTY] = gMonIcon_SkittyOld,
    [SPECIES_DELCATTY] = gMonIcon_DelcattyOld,
    [SPECIES_KECLEON] = gMonIcon_KecleonOld,
    [SPECIES_BALTOY] = gMonIcon_BaltoyOld,
    [SPECIES_CLAYDOL] = gMonIcon_ClaydolOld,
    [SPECIES_NOSEPASS] = gMonIcon_NosepassOld,
    [SPECIES_TORKOAL] = gMonIcon_TorkoalOld,
    [SPECIES_SABLEYE] = gMonIcon_SableyeOld,
    [SPECIES_BARBOACH] = gMonIcon_BarboachOld,
    [SPECIES_WHISCASH] = gMonIcon_WhiscashOld,
    [SPECIES_LUVDISC] = gMonIcon_LuvdiscOld,
    [SPECIES_CORPHISH] = gMonIcon_CorphishOld,
    [SPECIES_CRAWDAUNT] = gMonIcon_CrawdauntOld,
    [SPECIES_FEEBAS] = gMonIcon_FeebasOld,
    [SPECIES_MILOTIC] = gMonIcon_MiloticOld,
    [SPECIES_CARVANHA] = gMonIcon_CarvanhaOld,
    [SPECIES_SHARPEDO] = gMonIcon_SharpedoOld,
    [SPECIES_TRAPINCH] = gMonIcon_TrapinchOld,
    [SPECIES_VIBRAVA] = gMonIcon_VibravaOld,
    [SPECIES_FLYGON] = gMonIcon_FlygonOld,
    [SPECIES_MAKUHITA] = gMonIcon_MakuhitaOld,
    [SPECIES_HARIYAMA] = gMonIcon_HariyamaOld,
    [SPECIES_ELECTRIKE] = gMonIcon_ElectrikeOld,
    [SPECIES_MANECTRIC] = gMonIcon_ManectricOld,
    [SPECIES_NUMEL] = gMonIcon_NumelOld,
    [SPECIES_CAMERUPT] = gMonIcon_CameruptOld,
    [SPECIES_SPHEAL] = gMonIcon_SphealOld,
    [SPECIES_SEALEO] = gMonIcon_SealeoOld,
    [SPECIES_WALREIN] = gMonIcon_WalreinOld,
    [SPECIES_CACNEA] = gMonIcon_CacneaOld,
    [SPECIES_CACTURNE] = gMonIcon_CacturneOld,
    [SPECIES_SNORUNT] = gMonIcon_SnoruntOld,
    [SPECIES_GLALIE] = gMonIcon_GlalieOld,
    [SPECIES_LUNATONE] = gMonIcon_LunatoneOld,
    [SPECIES_SOLROCK] = gMonIcon_SolrockOld,
    [SPECIES_AZURILL] = gMonIcon_AzurillOld,
    [SPECIES_SPOINK] = gMonIcon_SpoinkOld,
    [SPECIES_GRUMPIG] = gMonIcon_GrumpigOld,
    [SPECIES_PLUSLE] = gMonIcon_PlusleOld,
    [SPECIES_MINUN] = gMonIcon_MinunOld,
    [SPECIES_MAWILE] = gMonIcon_MawileOld,
    [SPECIES_MEDITITE] = gMonIcon_MedititeOld,
    [SPECIES_MEDICHAM] = gMonIcon_MedichamOld,
    [SPECIES_SWABLU] = gMonIcon_SwabluOld,
    [SPECIES_ALTARIA] = gMonIcon_AltariaOld,
    [SPECIES_WYNAUT] = gMonIcon_WynautOld,
    [SPECIES_DUSKULL] = gMonIcon_DuskullOld,
    [SPECIES_DUSCLOPS] = gMonIcon_DusclopsOld,
    [SPECIES_ROSELIA] = gMonIcon_RoseliaOld,
    [SPECIES_SLAKOTH] = gMonIcon_SlakothOld,
    [SPECIES_VIGOROTH] = gMonIcon_VigorothOld,
    [SPECIES_SLAKING] = gMonIcon_SlakingOld,
    [SPECIES_GULPIN] = gMonIcon_GulpinOld,
    [SPECIES_SWALOT] = gMonIcon_SwalotOld,
    [SPECIES_TROPIUS] = gMonIcon_TropiusOld,
    [SPECIES_WHISMUR] = gMonIcon_WhismurOld,
    [SPECIES_LOUDRED] = gMonIcon_LoudredOld,
    [SPECIES_EXPLOUD] = gMonIcon_ExploudOld,
    [SPECIES_CLAMPERL] = gMonIcon_ClamperlOld,
    [SPECIES_HUNTAIL] = gMonIcon_HuntailOld,
    [SPECIES_GOREBYSS] = gMonIcon_GorebyssOld,
    [SPECIES_ABSOL] = gMonIcon_AbsolOld,
    [SPECIES_SHUPPET] = gMonIcon_ShuppetOld,
    [SPECIES_BANETTE] = gMonIcon_BanetteOld,
    [SPECIES_SEVIPER] = gMonIcon_SeviperOld,
    [SPECIES_ZANGOOSE] = gMonIcon_ZangooseOld,
    [SPECIES_RELICANTH] = gMonIcon_RelicanthOld,
    [SPECIES_ARON] = gMonIcon_AronOld,
    [SPECIES_LAIRON] = gMonIcon_LaironOld,
    [SPECIES_AGGRON] = gMonIcon_AggronOld,
    [SPECIES_CASTFORM] = gMonIcon_CastformOld,
    [SPECIES_VOLBEAT] = gMonIcon_VolbeatOld,
    [SPECIES_ILLUMISE] = gMonIcon_IllumiseOld,
    [SPECIES_LILEEP] = gMonIcon_LileepOld,
    [SPECIES_CRADILY] = gMonIcon_CradilyOld,
    [SPECIES_ANORITH] = gMonIcon_AnorithOld,
    [SPECIES_ARMALDO] = gMonIcon_ArmaldoOld,
    [SPECIES_RALTS] = gMonIcon_RaltsOld,
    [SPECIES_KIRLIA] = gMonIcon_KirliaOld,
    [SPECIES_GARDEVOIR] = gMonIcon_GardevoirOld,
    [SPECIES_BAGON] = gMonIcon_BagonOld,
    [SPECIES_SHELGON] = gMonIcon_ShelgonOld,
    [SPECIES_SALAMENCE] = gMonIcon_SalamenceOld,
    [SPECIES_BELDUM] = gMonIcon_BeldumOld,
    [SPECIES_METANG] = gMonIcon_MetangOld,
    [SPECIES_METAGROSS] = gMonIcon_MetagrossOld,
    [SPECIES_REGIROCK] = gMonIcon_RegirockOld,
    [SPECIES_REGICE] = gMonIcon_RegiceOld,
    [SPECIES_REGISTEEL] = gMonIcon_RegisteelOld,
    [SPECIES_KYOGRE] = gMonIcon_KyogreOld,
    [SPECIES_GROUDON] = gMonIcon_GroudonOld,
    [SPECIES_RAYQUAZA] = gMonIcon_RayquazaOld,
    [SPECIES_LATIAS] = gMonIcon_LatiasOld,
    [SPECIES_LATIOS] = gMonIcon_LatiosOld,
    [SPECIES_JIRACHI] = gMonIcon_JirachiOld,
    [SPECIES_DEOXYS] = gMonIcon_DeoxysOld,
    [SPECIES_CHIMECHO] = gMonIcon_ChimechoOld,
    [SPECIES_EGG] = gMonIcon_EggOld,
    [SPECIES_UNOWN_B] = gMonIcon_UnownBOld,
    [SPECIES_UNOWN_C] = gMonIcon_UnownCOld,
    [SPECIES_UNOWN_D] = gMonIcon_UnownDOld,
    [SPECIES_UNOWN_E] = gMonIcon_UnownEOld,
    [SPECIES_UNOWN_F] = gMonIcon_UnownFOld,
    [SPECIES_UNOWN_G] = gMonIcon_UnownGOld,
    [SPECIES_UNOWN_H] = gMonIcon_UnownHOld,
    [SPECIES_UNOWN_I] = gMonIcon_UnownIOld,
    [SPECIES_UNOWN_J] = gMonIcon_UnownJOld,
    [SPECIES_UNOWN_K] = gMonIcon_UnownKOld,
    [SPECIES_UNOWN_L] = gMonIcon_UnownLOld,
    [SPECIES_UNOWN_M] = gMonIcon_UnownMOld,
    [SPECIES_UNOWN_N] = gMonIcon_UnownNOld,
    [SPECIES_UNOWN_O] = gMonIcon_UnownOOld,
    [SPECIES_UNOWN_P] = gMonIcon_UnownPOld,
    [SPECIES_UNOWN_Q] = gMonIcon_UnownQOld,
    [SPECIES_UNOWN_R] = gMonIcon_UnownROld,
    [SPECIES_UNOWN_S] = gMonIcon_UnownSOld,
    [SPECIES_UNOWN_T] = gMonIcon_UnownTOld,
    [SPECIES_UNOWN_U] = gMonIcon_UnownUOld,
    [SPECIES_UNOWN_V] = gMonIcon_UnownVOld,
    [SPECIES_UNOWN_W] = gMonIcon_UnownWOld,
    [SPECIES_UNOWN_X] = gMonIcon_UnownXOld,
    [SPECIES_UNOWN_Y] = gMonIcon_UnownYOld,
    [SPECIES_UNOWN_Z] = gMonIcon_UnownZOld,
    [SPECIES_UNOWN_EMARK] = gMonIcon_UnownExclamationMarkOld,
    [SPECIES_UNOWN_QMARK] = gMonIcon_UnownQuestionMarkOld,
};

const u8 gMonIconPaletteIndices[] =
{
    [SPECIES_NONE] = 0,
    [SPECIES_BULBASAUR] = 1,
    [SPECIES_IVYSAUR] = 1,
    [SPECIES_VENUSAUR] = 1,
    [SPECIES_CHARMANDER] = 0,
    [SPECIES_CHARMELEON] = 0,
    [SPECIES_CHARIZARD] = 0,
    [SPECIES_SQUIRTLE] = 0,
    [SPECIES_WARTORTLE] = 2,
    [SPECIES_BLASTOISE] = 2,
    [SPECIES_CATERPIE] = 1,
    [SPECIES_METAPOD] = 1,
    [SPECIES_BUTTERFREE] = 0,
    [SPECIES_WEEDLE] = 1,
    [SPECIES_KAKUNA] = 2,
    [SPECIES_BEEDRILL] = 2,
    [SPECIES_PIDGEY] = 0,
    [SPECIES_PIDGEOTTO] = 0,
    [SPECIES_PIDGEOT] = 0,
    [SPECIES_RATTATA] = 2,
    [SPECIES_RATICATE] = 1,
    [SPECIES_SPEAROW] = 0,
    [SPECIES_FEAROW] = 0,
    [SPECIES_EKANS] = 2,
    [SPECIES_ARBOK] = 2,
    [SPECIES_PIKACHU] = 2,
    [SPECIES_RAICHU] = 0,
    [SPECIES_SANDSHREW] = 2,
    [SPECIES_SANDSLASH] = 2,
    [SPECIES_NIDORAN_F] = 2,
    [SPECIES_NIDORINA] = 2,
    [SPECIES_NIDOQUEEN] = 2,
    [SPECIES_NIDORAN_M] = 2,
    [SPECIES_NIDORINO] = 2,
    [SPECIES_NIDOKING] = 2,
    [SPECIES_CLEFAIRY] = 0,
    [SPECIES_CLEFABLE] = 0,
    [SPECIES_VULPIX] = 2,
    [SPECIES_NINETALES] = 1,
    [SPECIES_JIGGLYPUFF] = 0,
    [SPECIES_WIGGLYTUFF] = 0,
    [SPECIES_ZUBAT] = 2,
    [SPECIES_GOLBAT] = 2,
    [SPECIES_ODDISH] = 1,
    [SPECIES_GLOOM] = 0,
    [SPECIES_VILEPLUME] = 0,
    [SPECIES_PARAS] = 0,
    [SPECIES_PARASECT] = 0,
    [SPECIES_VENONAT] = 0,
    [SPECIES_VENOMOTH] = 2,
    [SPECIES_DIGLETT] = 2,
    [SPECIES_DUGTRIO] = 2,
    [SPECIES_MEOWTH] = 1,
    [SPECIES_PERSIAN] = 1,
    [SPECIES_PSYDUCK] = 1,
    [SPECIES_GOLDUCK] = 2,
    [SPECIES_MANKEY] = 1,
    [SPECIES_PRIMEAPE] = 2,
    [SPECIES_GROWLITHE] = 0,
    [SPECIES_ARCANINE] = 0,
    [SPECIES_POLIWAG] = 0,
    [SPECIES_POLIWHIRL] = 0,
    [SPECIES_POLIWRATH] = 0,
    [SPECIES_ABRA] = 2,
    [SPECIES_KADABRA] = 2,
    [SPECIES_ALAKAZAM] = 2,
    [SPECIES_MACHOP] = 0,
    [SPECIES_MACHOKE] = 2,
    [SPECIES_MACHAMP] = 0,
    [SPECIES_BELLSPROUT] = 1,
    [SPECIES_WEEPINBELL] = 1,
    [SPECIES_VICTREEBEL] = 1,
    [SPECIES_TENTACOOL] = 2,
    [SPECIES_TENTACRUEL] = 2,
    [SPECIES_GEODUDE] = 1,
    [SPECIES_GRAVELER] = 1,
    [SPECIES_GOLEM] = 1,
    [SPECIES_PONYTA] = 0,
    [SPECIES_RAPIDASH] = 0,
    [SPECIES_SLOWPOKE] = 0,
    [SPECIES_SLOWBRO] = 0,
    [SPECIES_MAGNEMITE] = 0,
    [SPECIES_MAGNETON] = 0,
    [SPECIES_FARFETCHD] = 1,
    [SPECIES_DODUO] = 2,
    [SPECIES_DODRIO] = 2,
    [SPECIES_SEEL] = 2,
    [SPECIES_DEWGONG] = 2,
    [SPECIES_GRIMER] = 2,
    [SPECIES_MUK] = 2,
    [SPECIES_SHELLDER] = 2,
    [SPECIES_CLOYSTER] = 2,
    [SPECIES_GASTLY] = 2,
    [SPECIES_HAUNTER] = 2,
    [SPECIES_GENGAR] = 2,
    [SPECIES_ONIX] = 2,
    [SPECIES_DROWZEE] = 2,
    [SPECIES_HYPNO] = 1,
    [SPECIES_KRABBY] = 2,
    [SPECIES_KINGLER] = 2,
    [SPECIES_VOLTORB] = 0,
    [SPECIES_ELECTRODE] = 0,
    [SPECIES_EXEGGCUTE] = 0,
    [SPECIES_EXEGGUTOR] = 1,
    [SPECIES_CUBONE] = 1,
    [SPECIES_MAROWAK] = 1,
    [SPECIES_HITMONLEE] = 2,
    [SPECIES_HITMONCHAN] = 2,
    [SPECIES_LICKITUNG] = 1,
    [SPECIES_KOFFING] = 2,
    [SPECIES_WEEZING] = 2,
    [SPECIES_RHYHORN] = 1,
    [SPECIES_RHYDON] = 1,
    [SPECIES_CHANSEY] = 0,
    [SPECIES_TANGELA] = 0,
    [SPECIES_KANGASKHAN] = 1,
    [SPECIES_HORSEA] = 0,
    [SPECIES_SEADRA] = 0,
    [SPECIES_GOLDEEN] = 0,
    [SPECIES_SEAKING] = 0,
    [SPECIES_STARYU] = 2,
    [SPECIES_STARMIE] = 2,
    [SPECIES_MR_MIME] = 0,
    [SPECIES_SCYTHER] = 1,
    [SPECIES_JYNX] = 2,
    [SPECIES_ELECTABUZZ] = 1,
    [SPECIES_MAGMAR] = 0,
    [SPECIES_PINSIR] = 2,
    [SPECIES_TAUROS] = 2,
    [SPECIES_MAGIKARP] = 0,
    [SPECIES_GYARADOS] = 0,
    [SPECIES_LAPRAS] = 2,
    [SPECIES_DITTO] = 2,
    [SPECIES_EEVEE] = 2,
    [SPECIES_VAPOREON] = 0,
    [SPECIES_JOLTEON] = 0,
    [SPECIES_FLAREON] = 0,
    [SPECIES_PORYGON] = 0,
    [SPECIES_OMANYTE] = 0,
    [SPECIES_OMASTAR] = 0,
    [SPECIES_KABUTO] = 2,
    [SPECIES_KABUTOPS] = 2,
    [SPECIES_AERODACTYL] = 0,
    [SPECIES_SNORLAX] = 1,
    [SPECIES_ARTICUNO] = 0,
    [SPECIES_ZAPDOS] = 0,
    [SPECIES_MOLTRES] = 0,
    [SPECIES_DRATINI] = 0,
    [SPECIES_DRAGONAIR] = 0,
    [SPECIES_DRAGONITE] = 2,
    [SPECIES_MEWTWO] = 2,
    [SPECIES_MEW] = 0,
    [SPECIES_CHIKORITA] = 1,
    [SPECIES_BAYLEEF] = 1,
    [SPECIES_MEGANIUM] = 1,
    [SPECIES_CYNDAQUIL] = 1,
    [SPECIES_QUILAVA] = 1,
    [SPECIES_TYPHLOSION] = 1,
    [SPECIES_TOTODILE] = 2,
    [SPECIES_CROCONAW] = 2,
    [SPECIES_FERALIGATR] = 2,
    [SPECIES_SENTRET] = 2,
    [SPECIES_FURRET] = 2,
    [SPECIES_HOOTHOOT] = 2,
    [SPECIES_NOCTOWL] = 2,
    [SPECIES_LEDYBA] = 0,
    [SPECIES_LEDIAN] = 0,
    [SPECIES_SPINARAK] = 1,
    [SPECIES_ARIADOS] = 0,
    [SPECIES_CROBAT] = 2,
    [SPECIES_CHINCHOU] = 2,
    [SPECIES_LANTURN] = 0,
    [SPECIES_PICHU] = 0,
    [SPECIES_CLEFFA] = 0,
    [SPECIES_IGGLYBUFF] = 1,
    [SPECIES_TOGEPI] = 2,
    [SPECIES_TOGETIC] = 2,
    [SPECIES_NATU] = 0,
    [SPECIES_XATU] = 0,
    [SPECIES_MAREEP] = 2,
    [SPECIES_FLAAFFY] = 0,
    [SPECIES_AMPHAROS] = 0,
    [SPECIES_BELLOSSOM] = 1,
    [SPECIES_MARILL] = 2,
    [SPECIES_AZUMARILL] = 2,
    [SPECIES_SUDOWOODO] = 1,
    [SPECIES_POLITOED] = 1,
    [SPECIES_HOPPIP] = 1,
    [SPECIES_SKIPLOOM] = 1,
    [SPECIES_JUMPLUFF] = 2,
    [SPECIES_AIPOM] = 2,
    [SPECIES_SUNKERN] = 1,
    [SPECIES_SUNFLORA] = 1,
    [SPECIES_YANMA] = 1,
    [SPECIES_WOOPER] = 0,
    [SPECIES_QUAGSIRE] = 0,
    [SPECIES_ESPEON] = 2,
    [SPECIES_UMBREON] = 2,
    [SPECIES_MURKROW] = 2,
    [SPECIES_SLOWKING] = 0,
    [SPECIES_MISDREAVUS] = 0,
    [SPECIES_UNOWN] = 0,
    [SPECIES_WOBBUFFET] = 0,
    [SPECIES_GIRAFARIG] = 1,
    [SPECIES_PINECO] = 0,
    [SPECIES_FORRETRESS] = 2,
    [SPECIES_DUNSPARCE] = 2,
    [SPECIES_GLIGAR] = 2,
    [SPECIES_STEELIX] = 0,
    [SPECIES_SNUBBULL] = 0,
    [SPECIES_GRANBULL] = 2,
    [SPECIES_QWILFISH] = 0,
    [SPECIES_SCIZOR] = 0,
    [SPECIES_SHUCKLE] = 1,
    [SPECIES_HERACROSS] = 2,
    [SPECIES_SNEASEL] = 0,
    [SPECIES_TEDDIURSA] = 0,
    [SPECIES_URSARING] = 2,
    [SPECIES_SLUGMA] = 0,
    [SPECIES_MAGCARGO] = 0,
    [SPECIES_SWINUB] = 2,
    [SPECIES_PILOSWINE] = 2,
    [SPECIES_CORSOLA] = 0,
    [SPECIES_REMORAID] = 0,
    [SPECIES_OCTILLERY] = 0,
    [SPECIES_DELIBIRD] = 0,
    [SPECIES_MANTINE] = 2,
    [SPECIES_SKARMORY] = 0,
    [SPECIES_HOUNDOUR] = 0,
    [SPECIES_HOUNDOOM] = 0,
    [SPECIES_KINGDRA] = 0,
    [SPECIES_PHANPY] = 0,
    [SPECIES_DONPHAN] = 0,
    [SPECIES_PORYGON2] = 0,
    [SPECIES_STANTLER] = 2,
    [SPECIES_SMEARGLE] = 1,
    [SPECIES_TYROGUE] = 2,
    [SPECIES_HITMONTOP] = 2,
    [SPECIES_SMOOCHUM] = 1,
    [SPECIES_ELEKID] = 1,
    [SPECIES_MAGBY] = 1,
    [SPECIES_MILTANK] = 1,
    [SPECIES_BLISSEY] = 1,
    [SPECIES_RAIKOU] = 0,
    [SPECIES_ENTEI] = 2,
    [SPECIES_SUICUNE] = 0,
    [SPECIES_LARVITAR] = 1,
    [SPECIES_PUPITAR] = 0,
    [SPECIES_TYRANITAR] = 1,
    [SPECIES_LUGIA] = 0,
    [SPECIES_HO_OH] = 1,
    [SPECIES_CELEBI] = 1,
    [SPECIES_OLD_UNOWN_B] = 0,
    [SPECIES_OLD_UNOWN_C] = 0,
    [SPECIES_OLD_UNOWN_D] = 0,
    [SPECIES_OLD_UNOWN_E] = 0,
    [SPECIES_OLD_UNOWN_F] = 0,
    [SPECIES_OLD_UNOWN_G] = 0,
    [SPECIES_OLD_UNOWN_H] = 0,
    [SPECIES_OLD_UNOWN_I] = 0,
    [SPECIES_OLD_UNOWN_J] = 0,
    [SPECIES_OLD_UNOWN_K] = 0,
    [SPECIES_OLD_UNOWN_L] = 0,
    [SPECIES_OLD_UNOWN_M] = 0,
    [SPECIES_OLD_UNOWN_N] = 0,
    [SPECIES_OLD_UNOWN_O] = 0,
    [SPECIES_OLD_UNOWN_P] = 0,
    [SPECIES_OLD_UNOWN_Q] = 0,
    [SPECIES_OLD_UNOWN_R] = 0,
    [SPECIES_OLD_UNOWN_S] = 0,
    [SPECIES_OLD_UNOWN_T] = 0,
    [SPECIES_OLD_UNOWN_U] = 0,
    [SPECIES_OLD_UNOWN_V] = 0,
    [SPECIES_OLD_UNOWN_W] = 0,
    [SPECIES_OLD_UNOWN_X] = 0,
    [SPECIES_OLD_UNOWN_Y] = 0,
    [SPECIES_OLD_UNOWN_Z] = 0,
    [SPECIES_TREECKO] = 1,
    [SPECIES_GROVYLE] = 0,
    [SPECIES_SCEPTILE] = 1,
    [SPECIES_TORCHIC] = 0,
    [SPECIES_COMBUSKEN] = 0,
    [SPECIES_BLAZIKEN] = 0,
    [SPECIES_MUDKIP] = 0,
    [SPECIES_MARSHTOMP] = 0,
    [SPECIES_SWAMPERT] = 0,
    [SPECIES_POOCHYENA] = 2,
    [SPECIES_MIGHTYENA] = 2,
    [SPECIES_ZIGZAGOON] = 2,
    [SPECIES_LINOONE] = 2,
    [SPECIES_WURMPLE] = 0,
    [SPECIES_SILCOON] = 2,
    [SPECIES_BEAUTIFLY] = 0,
    [SPECIES_CASCOON] = 2,
    [SPECIES_DUSTOX] = 1,
    [SPECIES_LOTAD] = 1,
    [SPECIES_LOMBRE] = 1,
    [SPECIES_LUDICOLO] = 1,
    [SPECIES_SEEDOT] = 1,
    [SPECIES_NUZLEAF] = 1,
    [SPECIES_SHIFTRY] = 0,
    [SPECIES_NINCADA] = 1,
    [SPECIES_NINJASK] = 1,
    [SPECIES_SHEDINJA] = 1,
    [SPECIES_TAILLOW] = 2,
    [SPECIES_SWELLOW] = 2,
    [SPECIES_SHROOMISH] = 1,
    [SPECIES_BRELOOM] = 1,
    [SPECIES_SPINDA] = 1,
    [SPECIES_WINGULL] = 0,
    [SPECIES_PELIPPER] = 0,
    [SPECIES_SURSKIT] = 2,
    [SPECIES_MASQUERAIN] = 0,
    [SPECIES_WAILMER] = 2,
    [SPECIES_WAILORD] = 0,
    [SPECIES_SKITTY] = 0,
    [SPECIES_DELCATTY] = 2,
    [SPECIES_KECLEON] = 1,
    [SPECIES_BALTOY] = 1,
    [SPECIES_CLAYDOL] = 0,
    [SPECIES_NOSEPASS] = 0,
    [SPECIES_TORKOAL] = 1,
    [SPECIES_SABLEYE] = 2,
    [SPECIES_BARBOACH] = 0,
    [SPECIES_WHISCASH] = 0,
    [SPECIES_LUVDISC] = 0,
    [SPECIES_CORPHISH] = 0,
    [SPECIES_CRAWDAUNT] = 0,
    [SPECIES_FEEBAS] = 2,
    [SPECIES_MILOTIC] = 0,
    [SPECIES_CARVANHA] = 0,
    [SPECIES_SHARPEDO] = 0,
    [SPECIES_TRAPINCH] = 1,
    [SPECIES_VIBRAVA] = 1,
    [SPECIES_FLYGON] = 1,
    [SPECIES_MAKUHITA] = 2,
    [SPECIES_HARIYAMA] = 1,
    [SPECIES_ELECTRIKE] = 1,
    [SPECIES_MANECTRIC] = 0,
    [SPECIES_NUMEL] = 1,
    [SPECIES_CAMERUPT] = 0,
    [SPECIES_SPHEAL] = 2,
    [SPECIES_SEALEO] = 2,
    [SPECIES_WALREIN] = 0,
    [SPECIES_CACNEA] = 1,
    [SPECIES_CACTURNE] = 1,
    [SPECIES_SNORUNT] = 2,
    [SPECIES_GLALIE] = 0,
    [SPECIES_LUNATONE] = 1,
    [SPECIES_SOLROCK] = 0,
    [SPECIES_AZURILL] = 2,
    [SPECIES_SPOINK] = 0,
    [SPECIES_GRUMPIG] = 2,
    [SPECIES_PLUSLE] = 0,
    [SPECIES_MINUN] = 0,
    [SPECIES_MAWILE] = 2,
    [SPECIES_MEDITITE] = 0,
    [SPECIES_MEDICHAM] = 0,
    [SPECIES_SWABLU] = 0,
    [SPECIES_ALTARIA] = 0,
    [SPECIES_WYNAUT] = 0,
    [SPECIES_DUSKULL] = 0,
    [SPECIES_DUSCLOPS] = 0,
    [SPECIES_ROSELIA] = 0,
    [SPECIES_SLAKOTH] = 2,
    [SPECIES_VIGOROTH] = 2,
    [SPECIES_SLAKING] = 1,
    [SPECIES_GULPIN] = 1,
    [SPECIES_SWALOT] = 2,
    [SPECIES_TROPIUS] = 1,
    [SPECIES_WHISMUR] = 0,
    [SPECIES_LOUDRED] = 2,
    [SPECIES_EXPLOUD] = 2,
    [SPECIES_CLAMPERL] = 0,
    [SPECIES_HUNTAIL] = 0,
    [SPECIES_GOREBYSS] = 0,
    [SPECIES_ABSOL] = 0,
    [SPECIES_SHUPPET] = 0,
    [SPECIES_BANETTE] = 0,
    [SPECIES_SEVIPER] = 2,
    [SPECIES_ZANGOOSE] = 0,
    [SPECIES_RELICANTH] = 1,
    [SPECIES_ARON] = 2,
    [SPECIES_LAIRON] = 2,
    [SPECIES_AGGRON] = 2,
    [SPECIES_CASTFORM] = 0,
    [SPECIES_VOLBEAT] = 0,
    [SPECIES_ILLUMISE] = 2,
    [SPECIES_LILEEP] = 2,
    [SPECIES_CRADILY] = 0,
    [SPECIES_ANORITH] = 0,
    [SPECIES_ARMALDO] = 0,
    [SPECIES_RALTS] = 1,
    [SPECIES_KIRLIA] = 1,
    [SPECIES_GARDEVOIR] = 1,
    [SPECIES_BAGON] = 2,
    [SPECIES_SHELGON] = 2,
    [SPECIES_SALAMENCE] = 0,
    [SPECIES_BELDUM] = 0,
    [SPECIES_METANG] = 0,
    [SPECIES_METAGROSS] = 0,
    [SPECIES_REGIROCK] = 2,
    [SPECIES_REGICE] = 2,
    [SPECIES_REGISTEEL] = 2,
    [SPECIES_KYOGRE] = 2,
    [SPECIES_GROUDON] = 0,
    [SPECIES_RAYQUAZA] = 1,
    [SPECIES_LATIAS] = 0,
    [SPECIES_LATIOS] = 2,
    [SPECIES_JIRACHI] = 0,
    [SPECIES_DEOXYS] = 0,
    [SPECIES_CHIMECHO] = 0,
    [SPECIES_EGG] = 1,
    [SPECIES_UNOWN_B] = 0,
    [SPECIES_UNOWN_C] = 0,
    [SPECIES_UNOWN_D] = 0,
    [SPECIES_UNOWN_E] = 0,
    [SPECIES_UNOWN_F] = 0,
    [SPECIES_UNOWN_G] = 0,
    [SPECIES_UNOWN_H] = 0,
    [SPECIES_UNOWN_I] = 0,
    [SPECIES_UNOWN_J] = 0,
    [SPECIES_UNOWN_K] = 0,
    [SPECIES_UNOWN_L] = 0,
    [SPECIES_UNOWN_M] = 0,
    [SPECIES_UNOWN_N] = 0,
    [SPECIES_UNOWN_O] = 0,
    [SPECIES_UNOWN_P] = 0,
    [SPECIES_UNOWN_Q] = 0,
    [SPECIES_UNOWN_R] = 0,
    [SPECIES_UNOWN_S] = 0,
    [SPECIES_UNOWN_T] = 0,
    [SPECIES_UNOWN_U] = 0,
    [SPECIES_UNOWN_V] = 0,
    [SPECIES_UNOWN_W] = 0,
    [SPECIES_UNOWN_X] = 0,
    [SPECIES_UNOWN_Y] = 0,
    [SPECIES_UNOWN_Z] = 0,
    [SPECIES_UNOWN_EMARK] = 0,
    [SPECIES_UNOWN_QMARK] = 0,
};

const struct SpritePalette gMonIconPaletteTable[] =
{
    { gMonIconPalettes[0], POKE_ICON_BASE_PAL_TAG + 0 },
    { gMonIconPalettes[1], POKE_ICON_BASE_PAL_TAG + 1 },
    { gMonIconPalettes[2], POKE_ICON_BASE_PAL_TAG + 2 },

    // There are only 3 actual palettes, but we repurpose the last 3 as duplicates for the new icon system
    { gMonIconPalettes[3 % 3], POKE_ICON_BASE_PAL_TAG + 3 },
    { gMonIconPalettes[4 % 3], POKE_ICON_BASE_PAL_TAG + 4 },
    { gMonIconPalettes[5 % 3], POKE_ICON_BASE_PAL_TAG + 5 },
};

static const struct OamData sMonIconOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

// fastest to slowest

static const union AnimCmd sAnim_0[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_2[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_3[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_4[] =
{
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_FRAME(0, 29), // frame 0 is repeated
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sMonIconAnims[] =
{
    sAnim_0,
    sAnim_1,
    sAnim_2,
    sAnim_3,
    sAnim_4,
};

static const union AffineAnimCmd sAffineAnim_0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_1[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 122),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sMonIconAffineAnims[] =
{
    sAffineAnim_0,
    sAffineAnim_1,
};

static const u16 sSpriteImageSizes[3][4] =
{
    [ST_OAM_SQUARE] =
    {
        [SPRITE_SIZE(8x8)]   =  8 * 8  / 2,
        [SPRITE_SIZE(16x16)] = 16 * 16 / 2,
        [SPRITE_SIZE(32x32)] = 32 * 32 / 2,
        [SPRITE_SIZE(64x64)] = 64 * 64 / 2,
    },
    [ST_OAM_H_RECTANGLE] =
    {
        [SPRITE_SIZE(16x8)]  = 16 * 8  / 2,
        [SPRITE_SIZE(32x8)]  = 32 * 8  / 2,
        [SPRITE_SIZE(32x16)] = 32 * 16 / 2,
        [SPRITE_SIZE(64x32)] = 64 * 32 / 2,
    },
    [ST_OAM_V_RECTANGLE] =
    {
        [SPRITE_SIZE(8x16)]  =  8 * 16 / 2,
        [SPRITE_SIZE(8x32)]  =  8 * 32 / 2,
        [SPRITE_SIZE(16x32)] = 16 * 32 / 2,
        [SPRITE_SIZE(32x64)] = 32 * 64 / 2,
    },
};

// Note: If you want to use this in your hack, be aware you must allocate palette slots for each icon,
// i.e via AllocSpritePalette, and set the sprite's palette with SetMonIconPalette
u8 CreateMonIcon(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality, bool32 handleDeoxys)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = GetMonIconPtr(species, personality, handleDeoxys),
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    if (species > NUM_SPECIES)
        iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG;

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u8 SetMonIconPalette(struct Pokemon *mon, struct Sprite *sprite, u8 paletteNum) {
  if (paletteNum < 16) {
    LoadCompressedPalette(GetMonFrontSpritePal(mon), paletteNum*16 + 0x100, 32);
    if (sprite)
      sprite->oam.paletteNum = paletteNum;
  }
  return paletteNum;
}

// Only used with mail and mystery event, which cannot really store a bit for a shiny pokemon,
// so we just load the palette into the proper slot by species
u8 CreateMonIconNoPersonality(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, bool32 handleDeoxys)
{
    u8 spriteId;
    u32 index = IndexOfSpritePaletteTag(POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species]);
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = NULL,
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    if (index < 16)
      LoadCompressedPalette(GetMonSpritePalFromSpeciesAndPersonality(species, 0, 0xFFFF), index*16 + 0x100, 32);

    iconTemplate.image = GetMonIconTiles(species, handleDeoxys);
    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u16 GetIconSpecies(u16 species, u32 personality)
{
    u16 result;

    if (species == SPECIES_UNOWN)
    {
        u16 letter = GetUnownLetterByPersonality(personality);
        if (letter == 0)
            letter = SPECIES_UNOWN;
        else
            letter += (SPECIES_UNOWN_B - 1);
        result = letter;
    }
    else
    {
        if (species > NUM_SPECIES)
            result = INVALID_ICON_SPECIES;
        else
            result = species;
    }

    return result;
}

u16 GetUnownLetterByPersonality(u32 personality)
{
    if (!personality)
        return 0;
    else
        return GET_UNOWN_LETTER(personality);
}

u16 GetIconSpeciesNoPersonality(u16 species)
{
    u16 value;

    if (MailSpeciesToSpecies(species, &value) == SPECIES_UNOWN)
    {
        if (value == 0)
            value += SPECIES_UNOWN;
        else
            value += (SPECIES_UNOWN_B - 1);
        return value;
    }
    else
    {
        if (species > NUM_SPECIES)
            species = INVALID_ICON_SPECIES;
        return GetIconSpecies(species, 0);
    }
}

// usage in menu.c is unused
const u8 *GetMonIconPtr(u16 species, u32 personality, bool32 handleDeoxys)
{
    return GetMonIconTiles(GetIconSpecies(species, personality), handleDeoxys);
}

void FreeAndDestroyMonIconSprite(struct Sprite *sprite)
{
    FreeAndDestroyMonIconSprite_(sprite);
}

void LoadMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        LoadSpritePalette(&gMonIconPaletteTable[i]);
}

// unused
void SafeLoadMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void LoadMonIconPalette(u16 species)
{
    u8 palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void FreeMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        FreeSpritePaletteByTag(gMonIconPaletteTable[i].tag);
}

// unused
void SafeFreeMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void FreeMonIconPalette(u16 species)
{
    u8 palIndex;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void SpriteCB_MonIcon(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

const u8 *GetMonIconTiles(u16 species, bool32 handleDeoxys)
{
    const u8 *iconSprite = gMonIconTable[species];
    if (species == SPECIES_DEOXYS && handleDeoxys == TRUE)
    {
        iconSprite = (const u8 *)(0x400 + (u32)iconSprite); // use the specific Deoxys form icon (Speed in this case)
    }
    return iconSprite;
}

// Loads pokemon icon palettes into the BG palettes, in the PC. Changed to always load an all-white palette.
void TryLoadAllMonIconPalettesAtOffset(u16 offset)
{
    s32 i;
    const struct SpritePalette* monIconPalettePtr;
    if (offset <= BG_PLTT_ID(16 - ARRAY_COUNT(gMonIconPaletteTable)))
    {
        u16 whitePalette[16];
        for (i = 0; i < 16; i++)
          whitePalette[i] = 0xFFFF;
        monIconPalettePtr = gMonIconPaletteTable;
        for(i = ARRAY_COUNT(gMonIconPaletteTable) - 1; i >= 0; i--)
        {
            LoadPalette(&whitePalette[0], offset, PLTT_SIZE_4BPP);
            offset += 16;
            monIconPalettePtr++;
        }
    }
}

// Unused as of icon upgrade
u8 GetValidMonIconPalIndex(u16 species)
{
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    return gMonIconPaletteIndices[species];
}

u8 GetMonIconPaletteIndexFromSpecies(u16 species)
{
    return gMonIconPaletteIndices[species];
}

// Unused as of icon upgrade
const u16 *GetValidMonIconPalettePtr(u16 species)
{
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    return gMonIconPaletteTable[gMonIconPaletteIndices[species]].data;
}

u8 UpdateMonIconFrame(struct Sprite *sprite)
{
    u8 result = 0;

    if (sprite->animDelayCounter == 0)
    {
        s16 frame = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;

        switch (frame)
        {
        case -1:
            break;
        case -2:
            sprite->animCmdIndex = 0;
            break;
        default:
            RequestSpriteCopy(
                // pointer arithmetic is needed to get the correct pointer to perform the sprite copy on.
                // because sprite->images is a struct def, it has to be casted to (u8 *) before any
                // arithmetic can be performed.
                (u8 *)sprite->images + (sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] * frame),
                (u8 *)(OBJ_VRAM0 + sprite->oam.tileNum * TILE_SIZE_4BPP),
                sSpriteImageSizes[sprite->oam.shape][sprite->oam.size]);
            sprite->animDelayCounter = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration & 0xFF;
            sprite->animCmdIndex++;
            result = sprite->animCmdIndex;
            break;
        }
    }
    else
    {
        sprite->animDelayCounter--;
    }
    return result;
}

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *iconTemplate, s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;

    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[iconTemplate->oam->shape][iconTemplate->oam->size] };

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = TAG_NONE,
        .paletteTag = iconTemplate->paletteTag,
        .oam = iconTemplate->oam,
        .anims = iconTemplate->anims,
        .images = &image,
        .affineAnims = iconTemplate->affineAnims,
        .callback = iconTemplate->callback,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    gSprites[spriteId].images = (const struct SpriteFrameImage *)iconTemplate->image;
    return spriteId;
}

static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite)
{
    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] };
    sprite->images = &image;
    DestroySprite(sprite);
}

void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}
