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
OcGopDrawQueryMode (
  IN  EFI_GRAPHICS_OUTPUT_PROTOCOL          *This,
  IN  UINT32                                ModeNumber,
  OUT UINTN                                 *SizeOfInfo,
  OUT EFI_GRAPHICS_OUTPUT_MODE_INFORMATION  **Info
  )
{
  if (ModeNumber != 0) {
    DEBUG ((DEBUG_VERBOSE, "OCC: OcGopDrawQueryMode invalid ModeNumber - %u\n", ModeNumber));
    return EFI_INVALID_PARAMETER;
  }

  if (SizeOfInfo == NULL || Info == NULL) {
    DEBUG ((DEBUG_VERBOSE, "OCC: OcGopDrawQueryMode got invalid parameter SizeOfInfo or Info!\n"));
    return EFI_INVALID_PARAMETER;
  }

  *SizeOfInfo = This->Mode->SizeOfInfo;
  *Info       = AllocateCopyPool (This->Mode->SizeOfInfo, This->Mode->Info);
  if (*Info == NULL) {
    DEBUG ((DEBUG_VERBOSE, "OCC: OcGopDrawQueryMode failed to allocate memory for GOP Info!\n"));
    return EFI_DEVICE_ERROR;
  }

  return EFI_SUCCESS;
}

STATIC
EFI_STATUS
EFIAPI
OcGopDrawSetMode (
  IN  EFI_GRAPHICS_OUTPUT_PROTOCOL  *This,
  IN  UINT32                        ModeNumber
  )
{
  if (ModeNumber != 0) {
    DEBUG ((DEBUG_VERBOSE, "OCC: OcGopDrawSetMode unsupported ModeNumber - %u\n", ModeNumber));
    return EFI_UNSUPPORTED;
  }

  //
  // Assuming 0 is the only mode that is accepted, which is already set.
  //
  return EFI_SUCCESS;
}

STATIC
EFI_STATUS
EFIAPI
OcGopDrawBlt (
  IN  EFI_GRAPHICS_OUTPUT_PROTOCOL            *This,
  IN  EFI_GRAPHICS_OUTPUT_BLT_PIXEL           *BltBuffer    OPTIONAL,
  IN  EFI_GRAPHICS_OUTPUT_BLT_OPERATION       BltOperation,
  IN  UINTN                                   SourceX,
  IN  UINTN                                   SourceY,
  IN  UINTN                                   DestinationX,
  IN  UINTN                                   DestinationY,
  IN  UINTN                                   Width,
  IN  UINTN                                   Height,
  IN  UINTN                                   Delta         OPTIONAL
  )
{
  OC_GOP_PROTOCOL  *OcGopDraw;

  OcGopDraw = BASE_CR (This, OC_GOP_PROTOCOL, GraphicsOutput);

  return OcGopDraw->Uga->Blt (
    OcGopDraw->Uga,
    (EFI_UGA_PIXEL *) BltBuffer,
    (EFI_UGA_BLT_OPERATION) BltOperation,
    SourceX,
    SourceY,
    DestinationX,
    DestinationY,
    Width,
    Height,
    Delta
    );
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

  Status = OcGopDrawQueryMode (NULL, 0, NULL, NULL);
  Status = OcGopDrawSetMode (NULL, 0);
  Status = OcGopDrawBlt (NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0);

  return Status;
}
