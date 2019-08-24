<!--
GENERATED FILE - DO NOT EDIT
This file was generated by [MarkdownSnippets](https://github.com/SimonCropp/MarkdownSnippets).
Source File: /doc/mdsource/Overview.source.md
To change this file edit the source file and then execute ./run_markdown_templates.sh.
-->

<a id="top"></a>

# Overview of Approval Tests

<!-- toc -->
## Contents

  * [Summary](#summary)
  * [Traditional Asserts](#traditional-asserts)
  * [Approval Tests](#approval-tests)
<!-- endtoc -->


## Summary

Approval Tests are an alternative way to write asserts in your test code.

As the following examples demonstrate, they give significantly simpler tests of complex objects.

## Traditional Asserts

Traditional tests spend equal time focusing on creating the inputs and verifying the outputs. 

When the objects being tested are non-trivial, either the tests become quite verbose (as shown in this example), or it's tempting to only test a small part of the behaviour.

```cpp
// Arrange, Act
Sandwich s = createSandwichForTest();
// Assert
REQUIRE("Sourdough" == s.getBread());
REQUIRE(s.getCondiments().contains("Mayo"));
REQUIRE(s.getCondiments().contains("Pepper"));
REQUIRE(s.getCondiments().contains("Olive Oil"));
REQUIRE(s.getFillings().contains("Tomato"));
REQUIRE(s.getFillings().contains("Lettuce"));
REQUIRE(s.getFillings().contains("Cheddar"));
```

## Approval Tests

Approval Tests simplify verification of the outputs. They do this by writing the outputs to a file, which once saved, becomes your spec.

You still supply the inputs, but Approval Tests gives you powerful ways of viewing complex outputs, meaning you can move on to the next feature or next test more quickly.

```cpp
// Arrange, Act
Sandwich s = createSandwichForTest();
// Assert
Approvals::verify(s);
```

This generates the approval file - which generated **for** you, but [approved **by** you](/doc/ApprovingResults.md#top).

```text
sandwich {
    bread: "Sourdough",
    condiments: ["Mayo", "Pepper", "Olive Oil"],
    fillings: ["Tomato", "Lettuce", "Cheddar"]
}
```

---

[Back to User Guide](/doc/README.md#top)