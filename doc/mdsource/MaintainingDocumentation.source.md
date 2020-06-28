<a id="top"></a>

# Maintaining Documentation

toc

We welcome improvements to the documentation! Here's how we manage the documentation files. 

## Future version numbers

To refer to the next release, use 'v.x.y.z', and make sure that there is a step to edit the file to update that text to the actual version number in the release scripts.

## Creating new pages

*Note: All the master Markdown pages in this project are called `mdsource/[something].source.md`*

**Using the template page**

If creating a new Markdown page, please make a copy of [doc/mdsource/TemplatePage.source.md](https://raw.githubusercontent.com/approvals/ApprovalTests.cpp/master/doc/mdsource/TemplatePage.source.md#top).
This contains some boilerplate text which is tedious to create by hand.

The new file needs to be in a `mdsource` sub-directory.

**Creating multiple pages**

If creating multiple files, on Unix, you can use the script `doc/mdsource/create_page.sh`

```bash
cd doc/mdsource/
./create_page.sh TestingSingleObjects TestingContainers TestingCombinations
```

This won't overwrite existing files.
It will write out the text to paste in to other .md files, to correctly link to the new file. 

**For documentation files outside of doc**

If the new page will be outside of the [doc](/doc/) folder, delete the following lines at the end:

```md
---
   
[Back to User Guide](/doc/README.md#top)
```

## Internal links need to be absolute 

All references to other files in this project, such as hyperlinks and images, must specify the full path from the root of the repository. This will allow those links to work correctly in both the source and generated markdown files. Relative paths cannot work for both the source and the target file. 

For example, use this:

```md
* [this link will work everywhere](/doc/Reporters.md#top)
```

Not this:

```md
* [this link is wrong](doc/Reporters.md#top)
```

And not this:

```md
* [this link is wrong](Reporters.md#top)
```

## Adding code and file samples

We use Simon Cropp's [MarkdownSnippets](https://github.com/SimonCropp/MarkdownSnippets) tool to embed source code and other files in Markdown pages.

**How it works:**

* Call the source file `[something].source.md`.
* Make sure it is in a `mdsource` directory
* See the [MarkdownSnippets](https://github.com/SimonCropp/MarkdownSnippets) documentation for how to:
    * annotate snippets of source code, 
    * reference the snippets in documentation.
* Run  `run_markdown_templates.sh` **before commit**, every time a `.source.md` file is updated
    * See [run_markdown_templates.sh](/run_markdown_templates.sh).
    * This will update the tables of contents and the machine-generated `[something].md` files.
    * If this does not work, see that script for how to install the tools it uses

### Managing CMake code samples

The repository [claremacrae/ApprovalTests.cpp.CMakeSamples](https://github.com/claremacrae/ApprovalTests.cpp.CMakeSamples) has some sample CMake projects for using ApprovalTests.cpp in various development scenarios.

When I improve the files in that repo, I run its script [claremacrae/ApprovalTests.cpp.CMakeSamples/create_markdown.py](https://github.com/claremacrae/ApprovalTests.cpp.CMakeSamples/blob/master/create_markdown.py) to convert the interesting CMake files to Markdown.

Some of those Markdown files are then embedded in the documentation for this project.

* See [CMakeIntegration.source.md](/doc/mdsource/CMakeIntegration.source.md) for the `include:` lines that do the inclusion
* See [CMakeIntegration.md](/doc/CMakeIntegration.md) for the final result.

## Checking the documentation

### Automated checking of links in documentation

There is a "markdown-link-check" github workflow that checks for broken links all in the Markdown files. It checks for missing file names, but will not detect missing anchors.

* It runs the script [scripts/check_links.sh](/scripts/check_links.sh) ...
* ... which uses the configuration file [mlc_config.json](/mlc_config.json) ...
* ... and runs [tcort's markdown-link-check](https://github.com/tcort/markdown-link-check)

If there are any failures, the output is slightly verbose to look through - you have to find lines beginning `[*]`, but I think that these will be sufficiently few and far between that this is good enough.

### Other checks of documentation

The script [fix_markdown.sh](/fix_markdown.sh) can be used to do some checks of the Markdown documentation files.

---

[Back to User Guide](/doc/README.md#top)