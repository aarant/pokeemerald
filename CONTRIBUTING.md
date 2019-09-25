# Contributing

If possible, join the Pret [Discord server](https://discord.gg/6EuWgX9) for discussion about contributions.

## Pull Request Flow
1. Make sure any miscellaneous files (emulator save states, IDE caches, etc) have not been accidentally committed.
2. **Make sure your changes build a matching ROM**. You can check this by running `make compare`.
3. Open a PR and briefly document your changes in the title (decompilation, documentation, etc).
Include information such as what file(s) you changed.

## Naming Conventions
Naming conventions keep the codebase clear and consistent, and enable other contributors and users to understand
what an object is at a glance.

* Function names should be **PascalCase**. This also applies to function-like macros.
* Global variables should be **Snake_case**, and prefixed with a lowercase `g` like `gGlobal_var`.
* Static variables should be **Snake_case**, and prefixed with a lowercase `s` like `sStatic_var`.
* Struct/typedef names should be **PascalCase**.

## Code of Conduct
TODO
