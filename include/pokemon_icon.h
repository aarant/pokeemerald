#ifndef GUARD_POKEMON_ICON_H
#define GUARD_POKEMON_ICON_H

extern const u8 gMonIconPaletteIndices[];
extern const u8 *const gMonIconTable[];
extern const struct SpritePalette gMonIconPaletteTable[];
extern const struct SpritePalette gMonIconIwramPaletteTable[];

const u8 *GetMonIconTiles(u16 species, bool32 handleDeoxys);
void TryLoadAllMonIconPalettesAtOffset(u16 offset);
u8 GetValidMonIconPalIndex(u16 species);
const u8 *GetMonIconPtr(u16 speciesId, u32 personality, u32 frameNo);
const u16 *GetValidMonIconPalettePtr(u16 species);
u16 GetIconSpecies(u16 species, u32 personality);
u16 GetUnownLetterByPersonality(u32 personality);
u16 GetIconSpeciesNoPersonality(u16 species);
void LoadMonIconPalettes(void);
void FreeMonIconPalettes(void);
u8 CreateMonIconNoPersonality(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, bool32 handleDeoxys);
void FreeAndDestroyMonIconSprite(struct Sprite *sprite);
u8 CreateMonIcon(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality, bool32 handleDeoxys);
u8 CreateMonIcon2(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 otId, u32 personality, bool32 handleDeoxys);
u8 CreateMonIcon3(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality, u8 paletteNum, bool32 handleDeoxys);
u8 SetMonIconPalette(struct Pokemon *, struct Sprite *, u8);
u8 UpdateMonIconFrame(struct Sprite *sprite);
void SpriteCB_MonIcon(struct Sprite *sprite);
void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum);
u8 GetMonIconPaletteIndexFromSpecies(u16 species);
void LoadSavedPartyIconGfxIwram(void);

#endif // GUARD_POKEMON_ICON_H
