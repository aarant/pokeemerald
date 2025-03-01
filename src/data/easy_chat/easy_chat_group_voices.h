const u8 gEasyChatWord_Excl[] = _E("!");
const u8 gEasyChatWord_ExclExcl[] = _E("!!");
const u8 gEasyChatWord_QuesExcl[] = _E("?!");
const u8 gEasyChatWord_Ques[] = _E("?");
const u8 gEasyChatWord_Ellipsis[] = _E("…");
const u8 gEasyChatWord_EllipsisExcl[] = _E("…!");
const u8 gEasyChatWord_EllipsisEllipsisEllipsis[] = _E("………");
const u8 gEasyChatWord_Dash[] = _E("-");
const u8 gEasyChatWord_DashDashDash[] = _E("- - -");
const u8 gEasyChatWord_UhOh[] = _E("UH-OH");
const u8 gEasyChatWord_Waaah[] = _E("WAAAH");
const u8 gEasyChatWord_Ahaha[] = _E("AHAHA");
const u8 gEasyChatWord_OhQues[] = _E("OH?");
const u8 gEasyChatWord_Nope[] = _E("NOPE");
const u8 gEasyChatWord_Urgh[] = _E("URGH");
const u8 gEasyChatWord_Hmm[] = _E("HMM");
const u8 gEasyChatWord_Whoah[] = _E("WHOAH");
const u8 gEasyChatWord_WroooaarExcl[] = _E("WROOOAAR!");
const u8 gEasyChatWord_Wow[] = _E("WOW");
const u8 gEasyChatWord_Giggle[] = _E("GIGGLE");
const u8 gEasyChatWord_Sigh[] = _E("SIGH");
const u8 gEasyChatWord_Unbelievable[] = _E("UNBELIEVABLE");
const u8 gEasyChatWord_Cries[] = _E("CRIES");
const u8 gEasyChatWord_Agree[] = _E("AGREE");
const u8 gEasyChatWord_EhQues[] = _E("EH?");
const u8 gEasyChatWord_Cry[] = _E("CRY");
const u8 gEasyChatWord_Ehehe[] = _E("EHEHE");
const u8 gEasyChatWord_OiOiOi[] = _E("OI, OI, OI");
const u8 gEasyChatWord_OhYeah[] = _E("OH, YEAH");
const u8 gEasyChatWord_Oh[] = _E("OH");
const u8 gEasyChatWord_Oops[] = _E("OOPS");
const u8 gEasyChatWord_Shocked[] = _E("SHOCKED");
const u8 gEasyChatWord_Eek[] = _E("EEK");
const u8 gEasyChatWord_Graaah[] = _E("GRAAAH");
const u8 gEasyChatWord_Gwahahaha[] = _E("GWAHAHAHA");
const u8 gEasyChatWord_Way[] = _E("WAY");
const u8 gEasyChatWord_Tch[] = _E("TCH");
const u8 gEasyChatWord_Hehe[] = _E("HEHE");
const u8 gEasyChatWord_Hah[] = _E("HAH");
const u8 gEasyChatWord_Yup[] = _E("YUP");
const u8 gEasyChatWord_Hahaha[] = _E("HAHAHA");
const u8 gEasyChatWord_Aiyeeh[] = _E("AIYEEH");
const u8 gEasyChatWord_Hiyah[] = _E("HIYAH");
const u8 gEasyChatWord_Fufufu[] = _E("FUFUFU");
const u8 gEasyChatWord_Lol[] = _E("LOL");
const u8 gEasyChatWord_Snort[] = _E("SNORT");
const u8 gEasyChatWord_Humph[] = _E("HUMPH");
const u8 gEasyChatWord_Hehehe[] = _E("HEHEHE");
const u8 gEasyChatWord_Heh[] = _E("HEH");
const u8 gEasyChatWord_Hohoho[] = _E("HOHOHO");
const u8 gEasyChatWord_UhHuh[] = _E("UH-HUH");
const u8 gEasyChatWord_OhDear[] = _E("OH, DEAR");
const u8 gEasyChatWord_Arrgh[] = _E("ARRGH");
const u8 gEasyChatWord_Mufufu[] = _E("MUFUFU");
const u8 gEasyChatWord_Mmm[] = _E("MMM");
const u8 gEasyChatWord_OhKay[] = _E("OH-KAY");
const u8 gEasyChatWord_Okay[] = _E("OKAY");
const u8 gEasyChatWord_Lalala[] = _E("LALALA");
const u8 gEasyChatWord_Yay[] = _E("YAY");
const u8 gEasyChatWord_Aww[] = _E("AWW");
const u8 gEasyChatWord_Wowee[] = _E("WOWEE");
const u8 gEasyChatWord_Gwah[] = _E("GWAH");
const u8 gEasyChatWord_Wahahaha[] = _E("WAHAHAHA");

const struct EasyChatWordInfo gEasyChatGroup_Voices[] = {
    [EC_INDEX(EC_WORD_EXCL)] =
    {
        .text = gEasyChatWord_Excl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCL_EXCL)] =
    {
        .text = gEasyChatWord_ExclExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCL_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUES_EXCL)] =
    {
        .text = gEasyChatWord_QuesExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DASH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_QUES)] =
    {
        .text = gEasyChatWord_Ques,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DASH_DASH_DASH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS)] =
    {
        .text = gEasyChatWord_Ellipsis,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS_EXCL)] =
    {
        .text = gEasyChatWord_EllipsisExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS)] =
    {
        .text = gEasyChatWord_EllipsisEllipsisEllipsis,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DASH)] =
    {
        .text = gEasyChatWord_Dash,
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DASH_DASH_DASH)] =
    {
        .text = gEasyChatWord_DashDashDash,
        .alphabeticalOrder = EC_INDEX(EC_WORD_QUES_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UH_OH)] =
    {
        .text = gEasyChatWord_UhOh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AGREE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAAAH)] =
    {
        .text = gEasyChatWord_Waaah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AHAHA)] =
    {
        .text = gEasyChatWord_Ahaha,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AIYEEH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_QUES)] =
    {
        .text = gEasyChatWord_OhQues,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ARRGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOPE)] =
    {
        .text = gEasyChatWord_Nope,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_URGH)] =
    {
        .text = gEasyChatWord_Urgh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRIES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HMM)] =
    {
        .text = gEasyChatWord_Hmm,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHOAH)] =
    {
        .text = gEasyChatWord_Whoah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EEK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WROOOAAR_EXCL)] =
    {
        .text = gEasyChatWord_WroooaarExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EH_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOW)] =
    {
        .text = gEasyChatWord_Wow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EHEHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIGGLE)] =
    {
        .text = gEasyChatWord_Giggle,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FUFUFU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIGH)] =
    {
        .text = gEasyChatWord_Sigh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIGGLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNBELIEVABLE)] =
    {
        .text = gEasyChatWord_Unbelievable,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRAAAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRIES)] =
    {
        .text = gEasyChatWord_Cries,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GWAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AGREE)] =
    {
        .text = gEasyChatWord_Agree,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GWAHAHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EH_QUES)] =
    {
        .text = gEasyChatWord_EhQues,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRY)] =
    {
        .text = gEasyChatWord_Cry,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EHEHE)] =
    {
        .text = gEasyChatWord_Ehehe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OI_OI_OI)] =
    {
        .text = gEasyChatWord_OiOiOi,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_YEAH)] =
    {
        .text = gEasyChatWord_OhYeah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEHEHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH)] =
    {
        .text = gEasyChatWord_Oh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIYAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OOPS)] =
    {
        .text = gEasyChatWord_Oops,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HMM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOCKED)] =
    {
        .text = gEasyChatWord_Shocked,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOHOHO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EEK)] =
    {
        .text = gEasyChatWord_Eek,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUMPH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRAAAH)] =
    {
        .text = gEasyChatWord_Graaah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LALALA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GWAHAHAHA)] =
    {
        .text = gEasyChatWord_Gwahahaha,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAY)] =
    {
        .text = gEasyChatWord_Way,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MMM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TCH)] =
    {
        .text = gEasyChatWord_Tch,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUFUFU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEHE)] =
    {
        .text = gEasyChatWord_Hehe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOPE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAH)] =
    {
        .text = gEasyChatWord_Hah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YUP)] =
    {
        .text = gEasyChatWord_Yup,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_DEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAHAHA)] =
    {
        .text = gEasyChatWord_Hahaha,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_YEAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AIYEEH)] =
    {
        .text = gEasyChatWord_Aiyeeh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_KAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIYAH)] =
    {
        .text = gEasyChatWord_Hiyah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OH_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FUFUFU)] =
    {
        .text = gEasyChatWord_Fufufu,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OI_OI_OI),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOL)] =
    {
        .text = gEasyChatWord_Lol,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OKAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SNORT)] =
    {
        .text = gEasyChatWord_Snort,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OOPS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUMPH)] =
    {
        .text = gEasyChatWord_Humph,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOCKED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEHEHE)] =
    {
        .text = gEasyChatWord_Hehehe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEH)] =
    {
        .text = gEasyChatWord_Heh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SNORT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOHOHO)] =
    {
        .text = gEasyChatWord_Hohoho,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UH_HUH)] =
    {
        .text = gEasyChatWord_UhHuh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UH_HUH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_DEAR)] =
    {
        .text = gEasyChatWord_OhDear,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UH_OH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ARRGH)] =
    {
        .text = gEasyChatWord_Arrgh,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNBELIEVABLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUFUFU)] =
    {
        .text = gEasyChatWord_Mufufu,
        .alphabeticalOrder = EC_INDEX(EC_WORD_URGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MMM)] =
    {
        .text = gEasyChatWord_Mmm,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAAAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OH_KAY)] =
    {
        .text = gEasyChatWord_OhKay,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAHAHAHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OKAY)] =
    {
        .text = gEasyChatWord_Okay,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LALALA)] =
    {
        .text = gEasyChatWord_Lalala,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YAY)] =
    {
        .text = gEasyChatWord_Yay,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWW)] =
    {
        .text = gEasyChatWord_Aww,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOWEE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOWEE)] =
    {
        .text = gEasyChatWord_Wowee,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WROOOAAR_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GWAH)] =
    {
        .text = gEasyChatWord_Gwah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAHAHAHA)] =
    {
        .text = gEasyChatWord_Wahahaha,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YUP),
        .enabled = TRUE,
    },
};
