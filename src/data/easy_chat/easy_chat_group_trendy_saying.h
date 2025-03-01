const u8 gEasyChatWord_KthxBye[] = _E("KTHX, BYE.");
const u8 gEasyChatWord_YesSirExcl[] = _E("YES, SIR!");
const u8 gEasyChatWord_AvantGarde[] = _E("AVANT GARDE");
const u8 gEasyChatWord_Couple[] = _E("COUPLE");
const u8 gEasyChatWord_MuchObliged[] = _E("MUCH OBLIGED");
const u8 gEasyChatWord_YeehawExcl[] = _E("YEEHAW!");
const u8 gEasyChatWord_Mega[] = _E("MEGA");
const u8 gEasyChatWord_1HitKOExcl[] = _E("1-HIT KO!");
const u8 gEasyChatWord_Destiny[] = _E("DESTINY");
const u8 gEasyChatWord_Cancel[] = _E("CANCEL");
const u8 gEasyChatWord_New[] = _E("NEW");
const u8 gEasyChatWord_Flatten[] = _E("FLATTEN");
const u8 gEasyChatWord_Kidding[] = _E("KIDDING");
const u8 gEasyChatWord_Loser[] = _E("LOSER");
const u8 gEasyChatWord_Losing[] = _E("LOSING");
const u8 gEasyChatWord_Happening[] = _E("HAPPENING");
const u8 gEasyChatWord_HipAnd[] = _E("HIP AND");
const u8 gEasyChatWord_Shake[] = _E("SHAKE");
const u8 gEasyChatWord_Shady[] = _E("SHADY");
const u8 gEasyChatWord_Upbeat[] = _E("UPBEAT");
const u8 gEasyChatWord_Modern[] = _E("MODERN");
const u8 gEasyChatWord_SmellYa[] = _E("SMELL YA");
const u8 gEasyChatWord_Bang[] = _E("BANG");
const u8 gEasyChatWord_Knockout[] = _E("KNOCKOUT");
const u8 gEasyChatWord_Hassle[] = _E("HASSLE");
const u8 gEasyChatWord_Winner[] = _E("WINNER");
const u8 gEasyChatWord_Fever[] = _E("FEVER");
const u8 gEasyChatWord_Wannabe[] = _E("WANNABE");
const u8 gEasyChatWord_Baby[] = _E("BABY");
const u8 gEasyChatWord_Heart[] = _E("HEART");
const u8 gEasyChatWord_Old[] = _E("OLD");
const u8 gEasyChatWord_Young[] = _E("YOUNG");
const u8 gEasyChatWord_Ugly[] = _E("UGLY");

const struct EasyChatWordInfo gEasyChatGroup_TrendySaying[] = {
    [EC_INDEX(EC_WORD_KTHX_BYE)] =
    {
        .text = gEasyChatWord_KthxBye,
        .alphabeticalOrder = EC_INDEX(EC_WORD_1_HIT_KO_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YES_SIR_EXCL)] =
    {
        .text = gEasyChatWord_YesSirExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AVANT_GARDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AVANT_GARDE)] =
    {
        .text = gEasyChatWord_AvantGarde,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BABY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COUPLE)] =
    {
        .text = gEasyChatWord_Couple,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BANG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH_OBLIGED)] =
    {
        .text = gEasyChatWord_MuchObliged,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CANCEL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEEHAW_EXCL)] =
    {
        .text = gEasyChatWord_YeehawExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COUPLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEGA)] =
    {
        .text = gEasyChatWord_Mega,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESTINY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_1_HIT_KO_EXCL)] =
    {
        .text = gEasyChatWord_1HitKOExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESTINY)] =
    {
        .text = gEasyChatWord_Destiny,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLATTEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CANCEL)] =
    {
        .text = gEasyChatWord_Cancel,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPENING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEW)] =
    {
        .text = gEasyChatWord_New,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HASSLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLATTEN)] =
    {
        .text = gEasyChatWord_Flatten,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEART),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIDDING)] =
    {
        .text = gEasyChatWord_Kidding,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIP_AND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSER)] =
    {
        .text = gEasyChatWord_Loser,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIDDING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSING)] =
    {
        .text = gEasyChatWord_Losing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOCKOUT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPENING)] =
    {
        .text = gEasyChatWord_Happening,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KTHX_BYE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIP_AND)] =
    {
        .text = gEasyChatWord_HipAnd,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHAKE)] =
    {
        .text = gEasyChatWord_Shake,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHADY)] =
    {
        .text = gEasyChatWord_Shady,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEGA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPBEAT)] =
    {
        .text = gEasyChatWord_Upbeat,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MODERN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MODERN)] =
    {
        .text = gEasyChatWord_Modern,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH_OBLIGED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMELL_YA)] =
    {
        .text = gEasyChatWord_SmellYa,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BANG)] =
    {
        .text = gEasyChatWord_Bang,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OLD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOCKOUT)] =
    {
        .text = gEasyChatWord_Knockout,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHADY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HASSLE)] =
    {
        .text = gEasyChatWord_Hassle,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WINNER)] =
    {
        .text = gEasyChatWord_Winner,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMELL_YA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEVER)] =
    {
        .text = gEasyChatWord_Fever,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UGLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANNABE)] =
    {
        .text = gEasyChatWord_Wannabe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPBEAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BABY)] =
    {
        .text = gEasyChatWord_Baby,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANNABE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEART)] =
    {
        .text = gEasyChatWord_Heart,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WINNER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OLD)] =
    {
        .text = gEasyChatWord_Old,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEEHAW_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOUNG)] =
    {
        .text = gEasyChatWord_Young,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YES_SIR_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UGLY)] =
    {
        .text = gEasyChatWord_Ugly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOUNG),
        .enabled = TRUE,
    },
};
