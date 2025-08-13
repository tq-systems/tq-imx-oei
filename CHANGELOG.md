# Changelog

Changelog for TQ-Systems GmbH fork of NXP OEI für i.MX95. See https://github.com/nxp-imx/imx-oei

[[_TOC_]]

All notable changes to this project will be documented in this file.

Releases are named with the following scheme:

`<TQ module family>.BSP.SW.<version number>`

## [Unreleased]

## Initial Version

TQ-Systems internal development based on NXP version lf-6.12.20-2.0.0
(Also merged additional changes from lf-6.6.52-2.2.1)

### Changed

* more / better info for DDR timing version and build in debug output banner
* allow DDR_MEM_TEST in DEBUG builds
* Update to NXP lf-6.12 release, necessary for i.MX95 B0 step

### Added

* support initial version of TQMa95xxSA REV.010x with 2/4 GiB LPDDR5
* support initial version of TQMa95xxLA REV.010x with 2/4 GiB LPDDR5
* infra: gitlab-ci support

