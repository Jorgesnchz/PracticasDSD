/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static resultado_calculadora *
_operacion_aritmetica_1 (operacion  *argp, struct svc_req *rqstp)
{
	return (operacion_aritmetica_1_svc(*argp, rqstp));
}

static resultado_calculadora *
_operacion_trigonometrica_2 (operacion_t  *argp, struct svc_req *rqstp)
{
	return (operacion_trigonometrica_2_svc(*argp, rqstp));
}

static resultado_calculadora_ecuaciones *
_operacion_ecuaciones_3 (operacion_e  *argp, struct svc_req *rqstp)
{
	return (operacion_ecuaciones_3_svc(*argp, rqstp));
}

static resultado_calculadora_vectores *
_operacion_vectores_4 (operacion_v  *argp, struct svc_req *rqstp)
{
	return (operacion_vectores_4_svc(*argp, rqstp));
}

static void
calculadora_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		operacion operacion_aritmetica_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case OPERACION_ARITMETICA:
		_xdr_argument = (xdrproc_t) xdr_operacion;
		_xdr_result = (xdrproc_t) xdr_resultado_calculadora;
		local = (char *(*)(char *, struct svc_req *)) _operacion_aritmetica_1;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

static void
calculadora_2(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		operacion_t operacion_trigonometrica_2_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case OPERACION_TRIGONOMETRICA:
		_xdr_argument = (xdrproc_t) xdr_operacion_t;
		_xdr_result = (xdrproc_t) xdr_resultado_calculadora;
		local = (char *(*)(char *, struct svc_req *)) _operacion_trigonometrica_2;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

static void
calculadora_3(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		operacion_e operacion_ecuaciones_3_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case OPERACION_ECUACIONES:
		_xdr_argument = (xdrproc_t) xdr_operacion_e;
		_xdr_result = (xdrproc_t) xdr_resultado_calculadora_ecuaciones;
		local = (char *(*)(char *, struct svc_req *)) _operacion_ecuaciones_3;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

static void
calculadora_4(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		operacion_v operacion_vectores_4_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case OPERACION_VECTORES:
		_xdr_argument = (xdrproc_t) xdr_operacion_v;
		_xdr_result = (xdrproc_t) xdr_resultado_calculadora_vectores;
		local = (char *(*)(char *, struct svc_req *)) _operacion_vectores_4;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (CALCULADORA, ARITMETICAS);
	pmap_unset (CALCULADORA, TRIGONOMETRICAS);
	pmap_unset (CALCULADORA, ECUACIONES);
	pmap_unset (CALCULADORA, VECTORES);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA, ARITMETICAS, calculadora_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA, ARITMETICAS, udp).");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA, TRIGONOMETRICAS, calculadora_2, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA, TRIGONOMETRICAS, udp).");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA, ECUACIONES, calculadora_3, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA, ECUACIONES, udp).");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA, VECTORES, calculadora_4, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA, VECTORES, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA, ARITMETICAS, calculadora_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA, ARITMETICAS, tcp).");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA, TRIGONOMETRICAS, calculadora_2, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA, TRIGONOMETRICAS, tcp).");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA, ECUACIONES, calculadora_3, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA, ECUACIONES, tcp).");
		exit(1);
	}
	if (!svc_register(transp, CALCULADORA, VECTORES, calculadora_4, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (CALCULADORA, VECTORES, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}