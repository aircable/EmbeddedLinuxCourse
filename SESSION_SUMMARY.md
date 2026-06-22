# Session Summary -- Embedded Linux Design Course

**Date:** 2026-06-19
**Agent:** NOVA (Embedded Linux Systems Educator)
**Model:** openrouter/owl-alpha
**Workspace:** `/share/projects/EmbeddedLinux/`

---

## Current State

The project has completed Phase 1 (PDF extraction and conversion). The directory is organized and all outputs are in their permanent locations on the mounted `/share` filesystem.

### Phase 1 -- COMPLETE: PDF to PPTX Conversion

All 10 chapter PDFs have been converted to PPTX files stored in `slides/`:

| PPTX File | Chapter | Size | Slides |
|-----------|---------|------|--------|
| ch01_Introduction.pptx | 1 - Introduction | 99 KB | 28 |
| ch02_Toolchains_and_Bootloaders.pptx | 2 - Toolchains & Bootloaders | 162 KB | 51 |
| ch03_Buildroot_and_Yocto.pptx | 3 - Yocto & Buildroot | 123 KB | 36 |
| ch04_System_Architecture.pptx | 4 - System Architecture | 125 KB | 34 |
| ch05_Build_Kernel_and_RootFS.pptx | 5 - Kernel Overview | 158 KB | 46 |
| ch06_Kernel_Architecture_and_Programming.pptx | 6 - Kernel Architecture | 97 KB | 25 |
| ch07_Linux_Systems_Programming.pptx | 7 - Systems Programming | 132 KB | 37 |
| ch08_Embedded_Applications.pptx | 8 - Embedded Applications | 109 KB | 29 |
| ch09_Debug_Optimize_Trace_Profile.pptx | 9 - Debug & Profiling | 188 KB | 54 |
| ch10_RTOS_Introduction.pptx | 10 - Realtime Systems | 45 KB | 14 |

**Total: 354 slides across 10 sessions.**

Plus ~750 page-level text extracts in `notes/` and reference PDFs in `docs/`.

### Phase 2 -- NOT STARTED: Quality Review

- Verify slide/notes split accuracy across all 10 PPTX decks
- Check for garbled text, missing titles, or misattributed sections
- Review pages flagged during extraction

### Phase 3 -- NOT STARTED: Content Modernization

- Update kernel versions, tool versions, best practices
- Add real-world examples, lab exercises, common failure modes
- Restructure slides for better instructional flow
- Verify all technical content against current Bootlin training materials and kernel.org

### Phase 4 -- NOT STARTED: Visual Design

- MODE 2 from the systems prompt
- Consistent color palette and typography across all decks
- Diagrams and architecture visuals replacing text walls
- Proper visual hierarchy: one key idea per slide

---

## Tooling & Infrastructure

### Knowledge Base (Open WebUI RAG)
- Open WebUI is pulling chunks from the "Embedded Linux Design - UCSC Extension" knowledge base
- Context is injected into each prompt via the RAG pipeline
- Contains Bootlin resource pages, kernel docs, and course reference material

### SearXNG Search Shortcuts
Self-hosted SearXNG instance with course-specific shortcuts:

| Shortcut | Engine | Use Case |
|----------|--------|----------|
| `!bootlin` | DuckDuckGo (Linux sites) | Bootlin training materials, kernel source |
| `!elixir` | Elixir Cross Referencer | Browse kernel source by version (elixir.bootlin.com) |
| `!korg` | kernel.org docs | Authoritative kernel API, subsystem behavior |
| `!lwn` | Linux Weekly News | Kernel development context, why things changed |
| `!yocto` | Yocto Project docs | Layer model, BitBake, release names, LTS status |

### Knowledge Graph (Planned)
- Deferred until after Phase 2 (quality review)
- Will map concept nodes and prerequisite relationships across all sessions
- Initial plan: Mermaid graph derived from verified slide content
- Future: proper graph database for dependency querying

---

## Topic Scan Results

Full slide-by-slide title extraction saved to `slide_topic_scan.json`.

### Session Topic Progression (Summary)

| Session | Topic | Slides | Key Concepts Covered |
|---------|-------|--------|---------------------|
| ch01 | Introduction | 28 | Linux advantages, embedded Linux elements, licenses (GPL/permissive), hardware selection, RT systems |
| ch02 | Toolchains & Bootloaders | 51 | Toolchain types, C libraries (glibc/uClibc/musl), crosstool-NG, boot sequence phases, device tree, U-Boot |
| ch03 | Buildroot & Yocto | 36 | Buildroot config/run, Yocto Project layers, BitBake, SDK creation, license compliance |
| ch04 | System Architecture | 34 | Flash memory (NOR/NAND), MTD, filesystems (JFFS2/UBIFS/ext4/F2FS/SquashFS), storage options |
| ch05 | Kernel Build & RootFS | 46 | Kernel build process, Kbuild, modules, device tree compilation, BusyBox, initramfs, init |
| ch06 | Kernel Architecture | 25 | Kernel subsystems (scheduler, MM, VFS, IPC, network), modules, sysfs, device drivers |
| ch07 | Systems Programming | 37 | Processes, threads (pthreads), IPC (pipes/sockets/shared memory), init (BusyBox/systemV/systemd), scheduling |
| ch08 | Embedded Applications | 29 | Python packaging (pip/setuptools/venv/conda), Docker deployment |
| ch09 | Debug & Profiling | 54 | GDB (remote/core/kernel), kgdb, perf, ftrace, LTTng, BPF, Valgrind, strace, memory management |
| ch10 | Realtime Systems | 14 | RT concepts, interrupt shielding, scheduling latency, preemption, high-resolution timers, page faults |

### Cross-Session Concept Dependencies (Preliminary)

```
ch01 (Intro, RT concepts)
  └── ch02 (Toolchains, Bootloaders, Device Tree)
        └── ch03 (Buildroot, Yocto)
              └── ch04 (System Arch, Flash, Filesystems)
                    └── ch05 (Kernel Build, RootFS, BusyBox)
                          └── ch06 (Kernel Architecture, Drivers, sysfs)
                                └── ch07 (Systems Programming, Processes, IPC, init)
                                      └── ch08 (Embedded Apps, Python, Docker)
                                      └── ch09 (Debug, Profiling, Memory)
                                            └── ch10 (Realtime, Preemption, Latency)
```

---

## Directory Layout

```
/share/projects/EmbeddedLinux/
    AGENT.md              -- agent instructions
    SESSION_SUMMARY.md    -- this file
    slide_topic_scan.json -- extracted slide titles (Phase 1.5)
    originals/            -- 17 source PDFs (archived)
    slides/               -- 10 PPTX files (Phase 1 output)
    notes/                -- 750+ per-page text extracts
    docs/                 -- 6 reference PDFs (Bootlin, Yocto, etc.)
    tools/                -- conversion scripts, slide library
```

## Source PDFs (all in originals/)

Main chapter slides (converted to PPTX):
1. Chapter 00 - Class Notes - Green Sheet.pdf
2. Chapter 00 - Class Notes - Objectives.pdf
3. Chapter 01 - a - Class Notes - Introduction.pdf
4. Chapter 02 - a - Class Notes - Toolchains and Bootloaders.pdf
5. Chapter 02 - a - Module Programming.pdf
6. Chapter 03 - a - Class Notes - Buildroot and Yocto Project.pdf
7. Chapter 03 - a - procfs sysfs and kernel debug.pdf
8. Chapter 04 - a - Class Notes - System Architecture.pdf
9. Chapter 05 - a - Class Notes - Build Kernel and RootFS.pdf
10. Chapter 06 - a - Class Notes - Linux Kernel Architecture and Programming.pdf
11. Chapter 07 - a - Class Notes - Linux Systems Programming.pdf
12. Chapter 08 - a - Class Notes - Embedded Applications.pdf
13. Chapter 09 - a - Class Notes - Debugging Optimizing Tracing Profiling Monitoring Makefile.pdf
14. Chapter 10 - a - Class Notes - Introduction to RTOS.pdf

Additional originals (different layout, not yet converted):
- Chapter 05 - More Reading - a - Chapter 02 LKDnotes - Module Programming.pdf
- Chapter 05 - More Reading - a - Chapter 03 LKDnotes - procfs sysfs and kernel debug.pdf
- Chapter 10 - b - Class Notes - Introduction to RTES.pdf

## Reference Docs (in docs/)

- bootlin-embedded-linux-slides.pdf (18.9 MB) -- Bootlin training
- embedded-linux-slides.pdf (18.9 MB) -- Bootlin training
- linux-kernel-slides.pdf (10.3 MB) -- Bootlin kernel
- yocto-slides.pdf (7.1 MB) -- Yocto Project
- buildroot-slides.pdf (9.8 MB) -- Buildroot
- preempt-rt-slides.pdf (5.1 MB) -- PREEMPT_RT

## Course Info

- **Course:** Embedded Linux Design
- **Institution:** UCSC Extension
- **Audience:** Working engineers, firmware engineers, system architects, career changers
- **Topics (10 sessions):** Intro, Toolchains/Bootloaders, Yocto/Buildroot, System Architecture, Kernel Overview, Kernel Architecture, Systems Programming, Embedded Apps, Debug/Profile, Realtime
