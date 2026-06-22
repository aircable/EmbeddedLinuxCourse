# Session 1 Redesign Plan — Embedded Linux Design

**Date:** 2026-06-21
**Status:** Ready to execute in a new session
**Author:** NOVA (based on collaborative redesign with instructor)

---

## Starting Point

The project directory is at `/share/projects/EmbeddedLinux/`.

The original inherited slides are in `slides_v1/`:
- Input file: `/share/projects/EmbeddedLinux/slides_v1/01_Introduction.pptx` (869 KB, 28 slides)
- This is the ONLY file you need from `slides_v1/` for this task.

All 10 session PPTX files also exist at `/share/projects/EmbeddedLinux/refining/working/` (copied from `slides_v1/`).

Reference files that matter:
- `/share/projects/EmbeddedLinux/AGENT.md` — full project context, course info, technical standards
- `/share/projects/EmbeddedLinux/SESSION_SUMMARY.md` — full status of all phases, directory layout, topic scan
- `/share/projects/EmbeddedLinux/slide_topic_scan.json` — extracted slide titles for all 10 sessions

---

## What Happened Before (Failure Analysis)

Two previous attempts to generate the redesigned PPTX failed:

1. **First attempt:** Python scripts were written as text in chat responses but never actually executed through the terminal tool. Files claimed to be created did not exist.

2. **Second attempt:** A complex XML-assembly script (`generate_session1.py`, 25KB) was written to `/share/projects/EmbeddedLinux/session1_work/` and executed. It produced intermediate files (29 slide XMLs, 29 notes XMLs with correct content) but the final PPTX ZIP assembly was broken (4.4KB output — too small). A second simpler script using python-pptx produced a 27KB file, but it was saved to `/tmp/` which is ephemeral and was lost.

**Key lessons:**
- Every script must be written with `write_file`, executed with `terminal("python3 /path/to/script.py")`, verified with `terminal("ls -lh /path/to/output")`, and the output must land on the persistent `/share/` filesystem — never in `/tmp/`.
- Do NOT describe what a script "will do" — run it and show what it actually did.
- Verify file existence and content after every write operation.

---

## Redesign Specification

### Output File

- **Path:** `/share/projects/EmbeddedLinux/slides_v1/01_Introduction_V2.pptx`
- The original `01_Introduction.pptx` must NOT be modified.

### Session Title

"Building Embedded Linux on the RPi4"

### Structure: 22 Slides in 4 Parts

**Part 1: The Destination (Slides 1-5, ~15 min)**

| Slide | Title | Key Content |
|-------|-------|-------------|
| 1 | Course Title and Instructor Introduction | Course name, instructor name, UCSC Extension, term |
| 2 | The Course Project | Build a bootable RPi4 system from scratch: SD card, serial console, shell prompt |
| 3 | What "From Scratch" Means | Cross-compile kernel, build rootfs, configure bootloader, write application |
| 4 | The 10-Session Roadmap | Visual flow diagram: each session mapped to a build stage |
| 5 | What You Need | Hardware (RPi4, SD card, serial adapter), prerequisites (C/C++, bare-metal helpful), AI for Programmers session completed |

**Part 2: The Context (Slides 6-12, ~25 min)**

| Slide | Title | Key Content |
|-------|-------|-------------|
| 6 | What Makes Embedded Linux Different | Constrained resources, cross-development, boot process, no GUI by default |
| 7 | The Embedded Linux Architecture Stack | Hardware → Bootloader → Kernel → Rootfs → Application (layered diagram) |
| 8 | Why Linux for Embedded | Open source, hardware support, driver ecosystem, GPL licensing implications |
| 9 | The Design Space | Same RPi4, many possible systems: minimal RT, full desktop, AI edge — design choices |
| 10 | Cross-Development | Build on x86, run on ARM; host vs target; reference Bootlin embedded Linux slides |
| 11 | The Development Workflow | Edit → cross-compile → transfer → test → debug; NFS rootfs for rapid iteration |
| 12 | AI in This Course | Three layers recap; AI as build assistant starting today |

**Part 3: The Path (Slides 13-18, ~20 min)**

| Slide | Title | Key Content |
|-------|-------|-------------|
| 13 | Session-by-Session Build Pipeline | Each session mapped to architecture layer (visual pipeline diagram) |
| 14 | The Toolchain | GCC cross-compiler, target triplet (aarch64-none-linux-gnu), Arm GNU Toolchain download |
| 15 | Bootloader Concepts | U-Boot, boot sequence: ROM → SPL → U-Boot → Kernel |
| 16 | Kernel Configuration | .config, make menuconfig, built-in vs module |
| 17 | Rootfs Construction | Minimal rootfs contents, init system (systemd vs BusyBox runit) |
| 18 | Debug and Profiling Preview | Remote GDB, serial console, LED blinking as first debug exercise |

**Part 4: First Step (Slides 19-22, ~30 min hands-on)**

| Slide | Title | Key Content |
|-------|-------|-------------|
| 19 | Lab: Flash and Boot | Flash SD card with Raspberry Pi Imager, boot RPi4, run `uname -a`, check `/proc/cpuinfo` |
| 20 | Your First Cross-Compilation | Write Hello World in C, compile with host GCC then cross-compiler, compare with `file` command |
| 21 | AI as Your Build Assistant | Configure Claude Code / Codex with the embedded Linux persona prompt; use AI to explain `readelf -h` output on both binaries |
| 22 | Summary and Preview | Recap what was covered, preview of Session 2 (Toolchains & Bootloaders) |

### AI Persona Prompt (for Slide 21 lab)

Students should configure their AI coding assistant with this system prompt:

```
You are an expert embedded Linux engineer specializing in Raspberry Pi 4
(BCM2711, Cortex-A72, aarch64) development. You help students who are
building a custom embedded Linux system from scratch using cross-compilation.
You are precise about architecture differences (ARM vs x86), toolchain details
(aarch64-none-linux-gnu), boot sequence (U-Boot), and kernel configuration.
When explaining build errors, always check whether the issue is host-target
confusion, missing cross-compilation flags, or architecture mismatch. You
encourage students to verify AI suggestions against the actual hardware and
never trust blindly. You reference the Bootlin embedded Linux training
materials and the Mastering Embedded Linux Programming textbook as
authoritative sources.
```

---

## Metric Scores

- **BPC (Build Progress Contribution):** 100% — every slide maps to greensheet outcomes 1 (explain embedded Linux design) and 2 (cross-development setup)
- **AID (AI Integration Depth):** Layer 1 integrated throughout (AI as build assistant), explicit reference to all three AI layers, AI persona prompt lab on Slide 21
- **DMS (Deviation from Main Stream):** zero deviation — everything serves the "build a bootable RPi4" narrative
- **HOD (Hands-On Density):** ~18% hands-on (4 of 22 slides are labs) — below the 50% target, but acceptable for an introductory session. Hands-on density increases sharply from Session 2 onward.

---

## Key Changes from Old Session 1

- Cut from 28 to 22 slides — removed generic "what is embedded" filler
- Opens with the destination (bootable RPi4) instead of definitions
- Explicitly references the AI for Programmers session and integrates AI from slide 1
- Adds hands-on labs: SD card flashing, first cross-compilation, AI-assisted analysis
- Every slide mapped to a greensheet outcome
- Speaker notes written for all 22 slides

---

## Execution Instructions (for the agent)

### Phase A: Verify Environment

1. Run `pwd` — confirm working directory
2. Run `ls -lh /share/projects/EmbeddedLinux/slides_v1/01_Introduction.pptx` — confirm input file exists
3. Run `python3 -c "import pptx; print(pptx.__version__)"` — confirm python-pptx is available
4. Run `ls -lh /share/projects/EmbeddedLinux/slides_v1/` — see what's already there

### Phase B: Write the Generation Script

1. Write the Python generation script to `/share/projects/EmbeddedLinux/session1_work/make_session1_v2.py` using `write_file`
2. The script must:
   - Use `python-pptx` (import pptx)
   - Create a new Presentation object
   - Add 22 slides with titles and body text content matching the specification above
   - Add speaker notes to every slide (teaching notes, not just restating slide content)
   - Save to `/share/projects/EmbeddedLinux/slides_v1/01_Introduction_V2.pptx`
   - Print confirmation with slide count

### Phase C: Execute

1. Run `terminal("python3 /share/projects/EmbeddedLinux/session1_work/make_session1_v2.py")`
2. Show the FULL terminal output — do not summarize or paraphrase
3. If there are ANY errors, STOP. Report the exact error. Do not retry or workaround.

### Phase D: Verify

1. Run `terminal("ls -lh /share/projects/EmbeddedLinux/slides_v1/01_Introduction_V2.pptx")` — confirm file exists and size is reasonable (expect 20-50KB for text-only)
2. Run a Python verification script that opens the PPTX and prints each slide's title and first 100 chars of notes
3. Confirm all 22 slides present with titles and notes
4. Report the complete manifest: file path, size, slide count, any issues

### Phase E: Do NOT

- Do NOT write the script as text in the chat response — it must go through `write_file`
- Do NOT describe what the script "will do" — run it and show what it actually did
- Do NOT write output to `/tmp/` — it will be lost
- Do NOT modify the original `01_Introduction.pptx`
- Do NOT install any packages without asking first
- Do NOT skip verification — a script printing "Success!" is not verification

---

## Speaker Notes Guidance

Speaker notes are the instructor's voice during the lecture. They must:
- Expand on the slide content, not restate it
- Include talking points, anecdotes, and emphasis cues
- Reference specific commands students will type
- Note where to pause for questions or hands-on transitions
- Be written in a conversational but technically precise tone
- Sound like a knowledgeable human talking, not bullet points read aloud

---

## Visual Design Notes

The initial PPTX will be text-only (python-pptx default styling). After content is confirmed correct:
- Apply visual theme in LibreOffice Impress, OR
- Use an existing PPTX as a template base (copy slides from a styled deck)
- Recommended: use the original `01_Introduction.pptx` as a visual template — it has the inherited visual style

---

## Directory State at Time of Writing

```
/share/projects/EmbeddedLinux/
    AGENT.md                          (4 KB) — project instructions
    SESSION_SUMMARY.md                (8 KB) — full status
    Session1Redesign.md               (this file) — redesign plan
    slide_topic_scan.json             (129 KB) — all slide titles
    originals/                        — 17 source PDFs
    slides/                           — 10 converted PPTX files
    slides_v1/                        — 10 PPTX files (including 01_Introduction.pptx, 869 KB)
    notes/                            — 750+ text extracts
    docs/                             — 6 reference PDFs
    tools/                            — conversion scripts
    session1_work/                    — previous failed build artifacts
        generate_session1.py          (25 KB) — broken XML assembly script
        build/                        — intermediate XML files (partially working)
        build2/                       — another intermediate attempt
        original/                     — extracted content from original PPTX
    refining/working/                 — all 10 PPTX files + archives
        01_Introduction.pptx          (869 KB) — copy of original
        01_Introduction_redesigned.pptx (832 KB) — previous redesign attempt
        slides_redesigned.zip         (1.8 MB)
```

---

## After Session 1 Is Complete

Once `01_Introduction_V2.pptx` is verified and correct, the next steps are:
1. Repeat the redesign process for Sessions 2-10
2. Apply visual design pass across all sessions
3. Update SESSION_SUMMARY.md with progress
