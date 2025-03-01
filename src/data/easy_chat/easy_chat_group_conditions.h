const u8 gEasyChatWord_Hot[] = _E("HOT");
const u8 gEasyChatWord_Exists[] = _E("EXISTS");
const u8 gEasyChatWord_Excess[] = _E("EXCESS");
const u8 gEasyChatWord_Approved[] = _E("APPROVED");
const u8 gEasyChatWord_Has[] = _E("HAS");
const u8 gEasyChatWord_Good[] = _E("GOOD");
const u8 gEasyChatWord_Less[] = _E("LESS");
const u8 gEasyChatWord_Momentum[] = _E("MOMENTUM");
const u8 gEasyChatWord_Going[] = _E("GOING");
const u8 gEasyChatWord_Weird[] = _E("WEIRD");
const u8 gEasyChatWord_Busy[] = _E("BUSY");
const u8 gEasyChatWord_Together[] = _E("TOGETHER");
const u8 gEasyChatWord_Full[] = _E("FULL");
const u8 gEasyChatWord_Absent[] = _E("ABSENT");
const u8 gEasyChatWord_Being[] = _E("BEING");
const u8 gEasyChatWord_Need[] = _E("NEED");
const u8 gEasyChatWord_Tasty[] = _E("TASTY");
const u8 gEasyChatWord_Skilled[] = _E("SKILLED");
const u8 gEasyChatWord_Noisy[] = _E("NOISY");
const u8 gEasyChatWord_Big[] = _E("BIG");
const u8 gEasyChatWord_Late[] = _E("LATE");
const u8 gEasyChatWord_Close[] = _E("CLOSE");
const u8 gEasyChatWord_Docile[] = _E("DOCILE");
const u8 gEasyChatWord_Amusing[] = _E("AMUSING");
const u8 gEasyChatWord_Entertaining[] = _E("ENTERTAINING");
const u8 gEasyChatWord_Perfection[] = _E("PERFECTION");
const u8 gEasyChatWord_Pretty[] = _E("PRETTY");
const u8 gEasyChatWord_Healthy[] = _E("HEALTHY");
const u8 gEasyChatWord_Excellent[] = _E("EXCELLENT");
const u8 gEasyChatWord_UpsideDown[] = _E("UPSIDE DOWN");
const u8 gEasyChatWord_Cold[] = _E("COLD");
const u8 gEasyChatWord_Refreshing[] = _E("REFRESHING");
const u8 gEasyChatWord_Unavoidable[] = _E("UNAVOIDABLE");
const u8 gEasyChatWord_Much[] = _E("MUCH");
const u8 gEasyChatWord_Overwhelming[] = _E("OVERWHELMING");
const u8 gEasyChatWord_Fabulous[] = _E("FABULOUS");
const u8 gEasyChatWord_Else[] = _E("ELSE");
const u8 gEasyChatWord_Expensive[] = _E("EXPENSIVE");
const u8 gEasyChatWord_Correct[] = _E("CORRECT");
const u8 gEasyChatWord_Impossible[] = _E("IMPOSSIBLE");
const u8 gEasyChatWord_Small[] = _E("SMALL");
const u8 gEasyChatWord_Different[] = _E("DIFFERENT");
const u8 gEasyChatWord_Tired[] = _E("TIRED");
const u8 gEasyChatWord_Skill[] = _E("SKILL");
const u8 gEasyChatWord_Top[] = _E("TOP");
const u8 gEasyChatWord_NonStop[] = _E("NON-STOP");
const u8 gEasyChatWord_Preposterous[] = _E("PREPOSTEROUS");
const u8 gEasyChatWord_None[] = _E("NONE");
const u8 gEasyChatWord_Nothing[] = _E("NOTHING");
const u8 gEasyChatWord_Natural[] = _E("NATURAL");
const u8 gEasyChatWord_Becomes[] = _E("BECOMES");
const u8 gEasyChatWord_Lukewarm[] = _E("LUKEWARM");
const u8 gEasyChatWord_Fast[] = _E("FAST");
const u8 gEasyChatWord_Low[] = _E("LOW");
const u8 gEasyChatWord_Awful[] = _E("AWFUL");
const u8 gEasyChatWord_Alone[] = _E("ALONE");
const u8 gEasyChatWord_Bored[] = _E("BORED");
const u8 gEasyChatWord_Secret[] = _E("SECRET");
const u8 gEasyChatWord_Mystery[] = _E("MYSTERY");
const u8 gEasyChatWord_Lacks[] = _E("LACKS");
const u8 gEasyChatWord_Best[] = _E("BEST");
const u8 gEasyChatWord_Lousy[] = _E("LOUSY");
const u8 gEasyChatWord_Mistake[] = _E("MISTAKE");
const u8 gEasyChatWord_Kind[] = _E("KIND");
const u8 gEasyChatWord_Well[] = _E("WELL");
const u8 gEasyChatWord_Weakened[] = _E("WEAKENED");
const u8 gEasyChatWord_Simple[] = _E("SIMPLE");
const u8 gEasyChatWord_Seems[] = _E("SEEMS");
const u8 gEasyChatWord_Badly[] = _E("BADLY");

const struct EasyChatWordInfo gEasyChatGroup_Conditions[] = {
    [EC_INDEX(EC_WORD_HOT)] =
    {
        .text = gEasyChatWord_Hot,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABSENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXISTS)] =
    {
        .text = gEasyChatWord_Exists,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCESS)] =
    {
        .text = gEasyChatWord_Excess,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AMUSING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPROVED)] =
    {
        .text = gEasyChatWord_Approved,
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPROVED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAS)] =
    {
        .text = gEasyChatWord_Has,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWFUL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD)] =
    {
        .text = gEasyChatWord_Good,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BADLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LESS)] =
    {
        .text = gEasyChatWord_Less,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BECOMES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOMENTUM)] =
    {
        .text = gEasyChatWord_Momentum,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOING)] =
    {
        .text = gEasyChatWord_Going,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEIRD)] =
    {
        .text = gEasyChatWord_Weird,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BIG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BUSY)] =
    {
        .text = gEasyChatWord_Busy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BORED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOGETHER)] =
    {
        .text = gEasyChatWord_Together,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUSY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FULL)] =
    {
        .text = gEasyChatWord_Full,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABSENT)] =
    {
        .text = gEasyChatWord_Absent,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEING)] =
    {
        .text = gEasyChatWord_Being,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CORRECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEED)] =
    {
        .text = gEasyChatWord_Need,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIFFERENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TASTY)] =
    {
        .text = gEasyChatWord_Tasty,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOCILE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILLED)] =
    {
        .text = gEasyChatWord_Skilled,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOISY)] =
    {
        .text = gEasyChatWord_Noisy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENTERTAINING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BIG)] =
    {
        .text = gEasyChatWord_Big,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCELLENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LATE)] =
    {
        .text = gEasyChatWord_Late,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLOSE)] =
    {
        .text = gEasyChatWord_Close,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXISTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOCILE)] =
    {
        .text = gEasyChatWord_Docile,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXPENSIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AMUSING)] =
    {
        .text = gEasyChatWord_Amusing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FABULOUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENTERTAINING)] =
    {
        .text = gEasyChatWord_Entertaining,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERFECTION)] =
    {
        .text = gEasyChatWord_Perfection,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FULL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRETTY)] =
    {
        .text = gEasyChatWord_Pretty,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEALTHY)] =
    {
        .text = gEasyChatWord_Healthy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOOD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCELLENT)] =
    {
        .text = gEasyChatWord_Excellent,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPSIDE_DOWN)] =
    {
        .text = gEasyChatWord_UpsideDown,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEALTHY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLD)] =
    {
        .text = gEasyChatWord_Cold,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REFRESHING)] =
    {
        .text = gEasyChatWord_Refreshing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMPOSSIBLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNAVOIDABLE)] =
    {
        .text = gEasyChatWord_Unavoidable,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH)] =
    {
        .text = gEasyChatWord_Much,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LACKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERWHELMING)] =
    {
        .text = gEasyChatWord_Overwhelming,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FABULOUS)] =
    {
        .text = gEasyChatWord_Fabulous,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELSE)] =
    {
        .text = gEasyChatWord_Else,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOUSY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXPENSIVE)] =
    {
        .text = gEasyChatWord_Expensive,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CORRECT)] =
    {
        .text = gEasyChatWord_Correct,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LUKEWARM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IMPOSSIBLE)] =
    {
        .text = gEasyChatWord_Impossible,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISTAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMALL)] =
    {
        .text = gEasyChatWord_Small,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOMENTUM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIFFERENT)] =
    {
        .text = gEasyChatWord_Different,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIRED)] =
    {
        .text = gEasyChatWord_Tired,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MYSTERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILL)] =
    {
        .text = gEasyChatWord_Skill,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOP)] =
    {
        .text = gEasyChatWord_Top,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NON_STOP)] =
    {
        .text = gEasyChatWord_NonStop,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOISY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PREPOSTEROUS)] =
    {
        .text = gEasyChatWord_Preposterous,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NON_STOP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NONE)] =
    {
        .text = gEasyChatWord_None,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOTHING)] =
    {
        .text = gEasyChatWord_Nothing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOTHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURAL)] =
    {
        .text = gEasyChatWord_Natural,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERWHELMING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BECOMES)] =
    {
        .text = gEasyChatWord_Becomes,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERFECTION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LUKEWARM)] =
    {
        .text = gEasyChatWord_Lukewarm,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PREPOSTEROUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAST)] =
    {
        .text = gEasyChatWord_Fast,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRETTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOW)] =
    {
        .text = gEasyChatWord_Low,
        .alphabeticalOrder = EC_INDEX(EC_WORD_REFRESHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWFUL)] =
    {
        .text = gEasyChatWord_Awful,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALONE)] =
    {
        .text = gEasyChatWord_Alone,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEEMS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BORED)] =
    {
        .text = gEasyChatWord_Bored,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIMPLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET)] =
    {
        .text = gEasyChatWord_Secret,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MYSTERY)] =
    {
        .text = gEasyChatWord_Mystery,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILLED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LACKS)] =
    {
        .text = gEasyChatWord_Lacks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMALL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEST)] =
    {
        .text = gEasyChatWord_Best,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TASTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOUSY)] =
    {
        .text = gEasyChatWord_Lousy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIRED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISTAKE)] =
    {
        .text = gEasyChatWord_Mistake,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOGETHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIND)] =
    {
        .text = gEasyChatWord_Kind,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL)] =
    {
        .text = gEasyChatWord_Well,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNAVOIDABLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEAKENED)] =
    {
        .text = gEasyChatWord_Weakened,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPSIDE_DOWN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIMPLE)] =
    {
        .text = gEasyChatWord_Simple,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEAKENED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEEMS)] =
    {
        .text = gEasyChatWord_Seems,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEIRD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BADLY)] =
    {
        .text = gEasyChatWord_Badly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELL),
        .enabled = TRUE,
    },
};
