/** @file
  Copyright (C) 2020, vit9696. All rights reserved.
  Copyright (C) 2021, PMheart. All rights reserved.

  All rights reserved.

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/

#include "OcConsoleLibInternal.h"

#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>

STATIC
EFI_STATUS
EFIAPI
OcGopDrawGetMode (
  IN  EFI_GRAPHICS_OUTPUT_PROTOCOL  *This,
  OUT UINT32                        *HorizontalResolution,
  OUT UINT32                        *VerticalResolution,
  OUT UINT32                        *ColorDepth,
  OUT UINT32                        *RefreshRate
  )
{
  //
  // TODO
  //
  return EFI_SUCCESS;
}

STATIC
EFI_STATUS
EFIAPI
OcGopDrawSetMode (
  IN  EFI_GRAPHICS_OUTPUT_PROTOCOL  *This,
  IN  UINT32                        HorizontalResolution,
  IN  UINT32                        VerticalResolution,
  IN  UINT32                        ColorDepth,
  IN  UINT32                        RefreshRate
  )
{
  //
  // TODO
  //
  return EFI_SUCCESS;
}

STATIC
EFI_STATUS
EFIAPI
OcGopDrawBlt (
  IN  EFI_GRAPHICS_OUTPUT_PROTOCOL            *This,
  IN  EFI_GRAPHICS_OUTPUT_BLT_PIXEL           *BltBuffer OPTIONAL,
  IN  EFI_GRAPHICS_OUTPUT_BLT_OPERATION       BltOperation,
  IN  UINTN                                   SourceX,
  IN  UINTN                                   SourceY,
  IN  UINTN                                   DestinationX,
  IN  UINTN                                   DestinationY,
  IN  UINTN                                   Width,
  IN  UINTN                                   Height,
  IN  UINTN                                   Delta      OPTIONAL
  )
{
  //
  // TODO
  //
  return EFI_SUCCESS;
}

EFI_STATUS
OcProvideGopPassThrough (
  VOID
  )
{
  //
  // TODO
  //
  EFI_STATUS  Status;

  Status = OcGopDrawGetMode (NULL, NULL, NULL, NULL, NULL);
  Status = OcGopDrawSetMode (NULL, 0, 0, 0, 0);
  Status = OcGopDrawBlt (NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0);

  return Status;
}
