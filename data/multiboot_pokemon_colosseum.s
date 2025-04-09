	.section .rodata

gMultiBootProgram_PokemonColosseum_Start::
	@ patches to this file and the [multiboot repo](https://github.com/pret/colosseum-mb)
	@ are found under `data/*.patch`
	.incbin "data/mb_colosseum.gba"
gMultiBootProgram_PokemonColosseum_End::
